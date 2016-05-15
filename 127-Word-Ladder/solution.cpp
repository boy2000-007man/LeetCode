class Solution {
    int ed(string &s1, string &s2) {
        int d = 0;
        for (int i = 0; s1[i] && d < 2; i++)
            d += s1[i] != s2[i];
        return d;
    }
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        vector<string> words(1, beginWord);
        for (auto &s: wordList)
            words.push_back(s);
        words.push_back(endWord);
        unordered_map<string, vector<int>> prefix, postfix;
        int len = beginWord.length(),
            llen = len >> 1,
            rlen = len - llen;
        for (int i = 0; i < words.size(); i++) {
            prefix[words[i].substr(0, llen)].push_back(i);
            postfix[words[i].substr(llen, rlen)].push_back(i);
        }
        vector<bool> visit(words.size(), false),
                     test(visit);
        visit[0] = true;
        queue<int> q;
        q.push(0);
        for (int depth = 0, num = 0; !q.empty(); q.pop()) {
            if (--num < 1)
                num = q.size(), depth++;
            string &word = words[q.front()];
            auto &pre = prefix[word.substr(0, llen)],
                 &post = postfix[word.substr(llen, rlen)];
            for (int idx: pre)
                if (!visit[idx] && !test[idx]) {
                    test[idx] = true;
                    if (ed(word, words[idx]) == 1)
                        if (idx == words.size() - 1)
                            return depth + 1;
                        else {
                            visit[idx] = true;
                            q.push(idx);
                        }
                }
            for (int idx: post)
                if (!visit[idx] && !test[idx]) {
                    test[idx] = true;
                    if (ed(word, words[idx]) == 1)
                        if (idx == words.size() - 1)
                            return depth + 1;
                        else {
                            visit[idx] = true;
                            q.push(idx);
                        }
                }
            for (int idx: pre)
                test[idx] = false;
            for (int idx: post)
                test[idx] = false;
        }
        return 0;
    }
};