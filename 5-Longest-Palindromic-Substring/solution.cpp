class Solution {
public:
    string longestPalindrome(string s) {
        int slen = s.length(),
            start = 0,
            len = 0;
        for (int i = 0; i < slen - len; i++) {
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
            while (l < r && len < l + r - 2 * i + 1)
                if (s[l] == s[r]) {
                    l++, r--;
                } else if ((l -= offset[l - i]) < i)
                    l = i, r--;
            if (len < l + r - 2 * i + 1)
                start = i, len = l + r - 2 * i + 1;
        }
        return s.substr(start, len);
    }
};