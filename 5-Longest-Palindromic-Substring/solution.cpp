class Solution {
public:
    string longestPalindrome(string s) {
        string longest;
        int slen = s.length(),
            llen = longest.length();
        for (int i = 0; i < slen - llen; i++) {
            vector<int> equal(slen - i >> 1, 1),
                        offset(equal.size(), 1);
            for (int j = 1; j < equal.size(); j++) {
                offset[j] = equal[j] = equal[j - 1];
                while (offset[j] <= j && s[i + j] == s[i + j - offset[j]])
                    offset[j] += offset[j - offset[j]];
                while (equal[j] <= j && s[i + j] != s[i + j - equal[j]])
                    equal[j] += offset[j - equal[j]];
            }
            int l = i,
                r = slen - 1;
            while (l < r && llen < l + r - 2 * i + 1)
                if (s[l] == s[r]) {
                    l++, r--;
                } else if ((l -= offset[l - i]) < i)
                    l = i, r--;
            if (llen < l + r - 2 * i + 1)
                longest = s.substr(i, llen = l + r - 2 * i + 1);
        }
        return longest;
    }
};