class Solution {
    bool alphanumeric(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9');
    }
public:
    bool isPalindrome(string s) {
        for (int l = 0, r = s.length() - 1; l < r; l++, r--) {
            while (l < r && !alphanumeric(s[l]))
                l++;
            while (l < r && !alphanumeric(s[r]))
                r--;
            if (l < r && tolower(s[l]) != tolower(s[r]))
                return false;
        }
        return true;
    }
};