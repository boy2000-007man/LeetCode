class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> occur(256, 0);
        int cnt = 0;
        for (char c: s)
            if (!occur[c]++)
                cnt++;
        for (char c: t)
            if (!--occur[c])
                cnt--;
            else if (occur[c] < 0)
                return false;
        return !cnt;
    }
};