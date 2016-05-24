class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> um[2];
        int i = 0;
        for ( ; s[i] && t[i]; i++) {
            char &s_ = um[0][s[i]],
                 &t_ = um[1][t[i]];
            if (!s_)
                s_ = t[i];
            else if (s_ != t[i])
                return false;
            if (!t_)
                t_ = s[i];
            else if (t_ != s[i])
                return false;
        }
        return !s[i] && !t[i];
    }
};