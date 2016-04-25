class Solution {
public:
    string shortestPalindrome(string s) {
        int len = s.length();
        vector<int> equal(len >> 1, 1),
                    offset(equal.size(), 1);
        for (int i = 1; i < equal.size(); i++) {
            offset[i] = equal[i] = equal[i - 1];
            while (offset[i] <= i && s[i - offset[i]] == s[i])
                offset[i] += offset[i - offset[i]];
            while (equal[i] <= i && s[i - equal[i]] != s[i])
                equal[i] += offset[i - equal[i]];
        }
        int end = len - 1;
        for (int j = 0; 0 <= end; )
            if (s[end] == s[j])
                if (end - j < 3)
                    break;
                else {
                    end--;
                    j++;
                }
            else if ((j -= offset[j]) < 0) {
                end--;
                j = 0;
            }
        string result;
        for (int i = len - 1; 0 <= i && end < i; i--)
            result += s[i];
        result += s;
        return result;
    }
};