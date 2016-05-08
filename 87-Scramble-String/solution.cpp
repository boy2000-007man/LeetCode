class Solution {
public:
    bool isScramble(const string &s1, const string &s2, int l1 = 0, int l2 = 0, int len = -1) {
        if (len < 0)
            len = s1.length();
        if (!len)
            return true;
        else if (len == 1)
            return s1[l1] == s2[l2];
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
            if (!num && i + 1 < len && isScramble(s1, s2, l1, l2, i + 1) && isScramble(s1, s2, l1 + i + 1, l2 + i + 1, len - i - 1))
                return true;
        }
        if (num)
            return false;
        for (int i = 0; i + 1 < len; i++) {
            if (!cnt[s1[l1 + i]]++)
                num--;
            else if (!cnt[s1[l1 + i]])
                num++;
            if (!cnt[s2[l2 + len - i - 1]]--)
                num--;
            else if (!cnt[s2[l2 + len - i - 1]])
                num++;
            if (!num && isScramble(s1, s2, l1, l2 + len - i - 1, i + 1) && isScramble(s1, s2, l1 + i + 1, l2, len - i - 1))
                return true;
        }
        return false;
    }
};