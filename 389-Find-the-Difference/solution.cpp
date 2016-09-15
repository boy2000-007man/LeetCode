class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26, 0);
        for (auto c: s)
            cnt[c - 'a']++;
        for (auto c: t)
            if (--cnt[c - 'a'] < 0)
                return c;
        return -1;
    }
};