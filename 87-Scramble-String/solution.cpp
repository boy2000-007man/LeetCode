class Solution {
    bool search(vector<vector<vector<int>>> &result, string &s1, string &s2, int l1, int l2, int len) {
        if (0 <= result[l1][l2][len])
            return result[l1][l2][len];
        if (!len)
            return result[l1][l2][len] = true;
        if (len == 1)
            return result[l1][l2][len] = s1[l1] == s2[l2];
        vector<int> cnt(256, 0);
        int num = 0;
        for (int i = 0; i < len; i++) {
            if (!cnt[s1[l1 + i]]++)
                num--;
            else if (!cnt[s1[l1 + i]])
                num++;
            if (!cnt[s2[l2 + i]]--)
                num--;
            else if (!cnt[s2[l2 + i]])
                num++;
            if (!num && i + 1 < len && search(result, s1, s2, l1, l2, i + 1) && search(result, s1, s2, l1 + i + 1, l2 + i + 1, len - i - 1))
                return result[l1][l2][len] = true;
        }
        if (num)
            return result[l1][l2][len] = false;
        for (int i = 0; i + 1 < len; i++) {
            if (!cnt[s1[l1 + i]]++)
                num--;
            else if (!cnt[s1[l1 + i]])
                num++;
            if (!cnt[s2[l2 + len - i - 1]]--)
                num--;
            else if (!cnt[s2[l2 + len - i - 1]])
                num++;
        if (!num && search(result, s1, s2, l1, l2 + len - i - 1, i + 1) && search(result, s1, s2, l1 + i + 1, l2, len - i - 1))
                return result[l1][l2][len] = true;
        }
        return result[l1][l2][len] = false;
    }
public:
    bool isScramble(string s1, string s2) {
        int len = s1.length();
        vector<vector<vector<int>>> result(len + 1, vector<vector<int>>(len + 1, vector<int>(len + 1, -1)));
        return search(result, s1, s2, 0, 0, len);
    }
};