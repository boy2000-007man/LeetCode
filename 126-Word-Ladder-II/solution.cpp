class Solution {
    struct trie {
        vector<int> indicies;
        trie *next[26];
        trie() : indicies(0) {
            memset(next, 0, sizeof(next));
        }
        ~trie() {
            for (int i = 0; i < 26; i++)
                if (next[i])
                    delete next[i];
        }
        void add(const char *s, int len, int idx) {
            trie *r = this;
            for ( ; len; s++, len--) {
                if (!r->next[*s - 'a'])
                    r->next[*s - 'a'] = new trie();
                r = r->next[*s - 'a'];
            }
            r->indicies.push_back(idx);
        }
        vector<int> &find(const char *s, int len) {
            trie *r = this;
            for ( ; len; s++, len--)
                r = r->next[*s - 'a'];
            return r->indicies;
        }
    };
    bool neighbour(const char *s1, const char *s2, int len) {
        int distance = 0;
        for ( ; len && distance < 2; s1++, s2++, len--)
            distance += (*s1 != *s2);
        if (distance == 1)
            return true;
        else
            return false;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<string> idx2wrd(1, beginWord);
        for (const string &s: wordList)
            idx2wrd.push_back(s);
        idx2wrd.push_back(endWord);
        int tot_len = beginWord.length(),
            pre_len = tot_len >> 1,
            suf_len = tot_len - pre_len;
        trie prefix, suffix;
        for (int i = 0; i < idx2wrd.size(); i++) {
            prefix.add(idx2wrd[i].c_str(), pre_len, i);
            suffix.add(idx2wrd[i].c_str() + pre_len, suf_len, i);
        }
        vector<vector<int>> idx2prev(idx2wrd.size(), vector<int>(0));
        list<int> queue(1, 0);
        vector<int> idx2depth(idx2wrd.size(), INT_MAX);
        for (int idx: queue)
            idx2depth[idx] = 1;
        vector<bool> next_idx2tst(idx2wrd.size(), false);
        for (int idx; !queue.empty() && idx2depth[idx = queue.front()] < idx2depth.back(); queue.pop_front())
            if (idx2depth.back() == INT_MAX) {
                vector<int> &pre = prefix.find(idx2wrd[idx].c_str(), pre_len),
                            &suf = suffix.find(idx2wrd[idx].c_str() + pre_len, suf_len);
                next_idx2tst[idx] = true;
                for (int next_idx: pre)
                    if (!next_idx2tst[next_idx]) {
                        if (idx2depth[idx] < idx2depth[next_idx]
                        && neighbour(idx2wrd[idx].c_str() + pre_len, idx2wrd[next_idx].c_str() + pre_len, suf_len)) {
                            idx2prev[next_idx].push_back(idx);
                            if (idx2depth[next_idx] == INT_MAX) {
                                queue.push_back(next_idx);
                                idx2depth[next_idx] = idx2depth[idx] + 1;
                            }
                        }
                        next_idx2tst[next_idx] = true;
                    }
                for (int next_idx: suf)
                    if (!next_idx2tst[next_idx]) {
                        if (idx2depth[idx] < idx2depth[next_idx]
                        && neighbour(idx2wrd[idx].c_str(), idx2wrd[next_idx].c_str(), pre_len)) {
                            idx2prev[next_idx].push_back(idx);
                            if (idx2depth[next_idx] == INT_MAX) {
                                queue.push_back(next_idx);
                                idx2depth[next_idx] = idx2depth[idx] + 1;
                            }
                        }
                        next_idx2tst[next_idx] = true;
                    }
                for (int next_idx: pre)
                    next_idx2tst[next_idx] = false;
                for (int next_idx: suf)
                    next_idx2tst[next_idx] = false;
            } else if (neighbour(idx2wrd[idx].c_str(), idx2wrd.back().c_str(), tot_len))
                idx2prev.back().push_back(idx);
        vector<vector<string>> result(0);
        if (idx2depth.back() == INT_MAX)
            return result;
        vector<string> route(idx2depth.back());
        route[0] = beginWord;
        route.back() = endWord;
        vector<int> order(idx2depth.back(), 0),
                    idx(idx2depth.back(), idx2wrd.size() - 1);
        for (int d = order.size() - 1; order.back() < idx2prev.back().size(); )
            if (order[d] < idx2prev[idx[d]].size()) {
                route[d - 1] = idx2wrd[idx[d - 1] = idx2prev[idx[d]][order[d]]];
                if (2 < d)
                    d--;
                else {
                    result.push_back(route);
                    order[d]++;
                }
            } else {
                order[d] = 0;
                order[++d]++;
            }
        return result;
    }
};