class Solution {
    void common(string &s1, string &s2) {
        int len = 0;
        while (s1[len] && s1[len] == s2[len])
            len++;
        s1.resize(len);
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        else {
            for (auto &s: strs)
                common(strs[0], s);
            return strs[0];
        }
    }
};