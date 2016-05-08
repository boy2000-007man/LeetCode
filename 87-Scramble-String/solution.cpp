class Solution {
public:
    bool isScramble(string s1, string s2) {
        bool result = s1 == s2;
        vector<int> cnt(256, 0);
        int num = 0,
            l = 0,
            r = s1.length() - 1;
        for (int m = l; m <= r && !result; m++) {
            if (!cnt[s1[m]]++)
                num--;
            else if (!cnt[s1[m]])
                num++;
            if (!cnt[s2[m]]--)
                num--;
            else if (!cnt[s2[m]])
                num++;
            if (m < r && !num)
                result = isScramble(s1.substr(l, m - l + 1), s2.substr(l, m - l + 1))
                        && isScramble(s1.substr(m + 1, r - m), s2.substr(m + 1, r - m));
        }
        for (int m = l; m < r && !result; m++) {
            if (!cnt[s1[m]]++)
                num--;
            else if (!cnt[s1[m]])
                num++;
            if (!cnt[s2[l + r - m]]--)
                num--;
            else if (!cnt[s2[l + r - m]])
                num++;
            if (!num)
                result = isScramble(s1.substr(l, m - l + 1), s2.substr(l + r - m, m - l + 1))
                        && isScramble(s1.substr(m + 1, r - m), s2.substr(l, r - m));
        }
        return result;
    }
};