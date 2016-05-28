class Solution {
    vector<int> calc(string &s) {
        int slen = s.length();
        vector<int> equ((slen >> 1) + 1, 1),
                    off(equ);
        for (int i = 1; i < equ.size(); i++) {
            equ[i] = off[i] = equ[i - 1];
            while (equ[i] <= i && s[i - equ[i]] != s[i])
                equ[i] += off[i - equ[i]];
            while (off[i] <= i && s[i - off[i]] == s[i])
                off[i] += off[i - off[i]];
        }
        vector<int> result;
        for (int i = 0, j = 0; j < slen; )
            if (slen - 1 - j <= i) {
                result.push_back(slen - 1 - (j - i));
                if ((i -= equ[i]) < 0)
                    i = 0, j++;
            } else if (s[i] == s[slen - 1 - j])
                i++, j++;
            else if ((i -= off[i]) < 0)
                i = 0, j++;
        return result;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> um;
        for (int i = 0; i < words.size(); i++) {
            reverse(begin(words[i]), end(words[i]));
            um[words[i]] = i;
        }
        vector<vector<int>> result;
        for (int i = 0; i < words.size(); i++) {
            string &word = words[i];
            int wlen = word.length();
            auto v = calc(word);
            reverse(begin(word), end(word));
            for (int l: v) {
                auto it = um.find(word.substr(0, wlen - 1 - l));
                if (it != um.end())
                    result.push_back({i, it->second});
            }
            auto it = um.find(word);
            if (it != um.end() && i != it->second)
                result.push_back({i, it->second});
            for (int l: calc(word)) {
                auto it = um.find(word.substr(l + 1));
                if (it != um.end())
                    result.push_back({it->second, i});
            }
        }
        return result;
    }
};