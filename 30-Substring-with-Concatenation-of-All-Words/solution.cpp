class Solution {
    struct dictionary_tree {
        int num;
        vector<pair<char, dictionary_tree *>> next;
        dictionary_tree() : num(0), next(0) {
        }
        ~dictionary_tree() {
            for (auto &p: next)
                if (p.second)
                    delete p.second;
        }
        int &operator[](const char *s) {
            dictionary_tree *r = this;
            for (int i = 0; s[i]; i++) {
                bool find = false;
                for (int j = 0; j < r->next.size() && !find; j++)
                    if (s[i] == r->next[j].first) {
                        find = true;
                        r = r->next[j].second;
                    }
                if (!find) {
                    r->next.push_back(make_pair(s[i], new dictionary_tree()));
                    r = r->next.back().second;
                }
            }
            return r->num;
        }
        int *find(const char *s, int length) {
            dictionary_tree *r = this;
            for (int i = 0; i < length; i++) {
                bool find = false;
                for (int j = 0; j < r->next.size() && !find; j++)
                    if (s[i] == r->next[j].first) {
                        find = true;
                        r = r->next[j].second;
                    }
                if (!find)
                    return NULL;
            }
            return &r->num;
        }
    };
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result(0),
                    count(1, 0),
                    bitmap(256, 0),
                    bitmap_own(256, 0);
        dictionary_tree s2i;
        int required = 0;
        for (string &word: words) {
            int &i = s2i[word.c_str()];
            if (!i) {
                i = count.size();
                count.push_back(1);
            } else
                count[i]++;
            for (char c: word)
                if (!(bitmap[c]++))
                    required++;
        }
        int length = words[0].length(),
            total_length = words.size() * length;
        for (int i = 0; s[i]; i++) {
            if (total_length < i)
                if (bitmap_own[s[i - total_length]]-- == bitmap[s[i - total_length]])
                    required++;
            if (++bitmap_own[s[i]] == bitmap[s[i]])
                required--;
            if (!required) {
                bool sub = true;
                vector<int> count_own(count.size(), 0);
                for (int j = 0; j < words.size() && sub; j++) {
                    int *res = s2i.find(s.c_str() + i - total_length + 1 + j * length, length);
                    if (!res || count[*res] < ++count_own[*res])
                        sub = false;
                }
                if (sub)
                    result.push_back(i - total_length + 1);
            }
        }
        return result;
    }
};