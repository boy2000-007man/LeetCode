class Solution {
public:
    bool isNumber(string s) {
        int l = 0;
        bool n = false;
        while (s[l] == ' ')
            l++;
        if (s[l] == '+' || s[l] == '-')
            l++;
        while ('0' <= s[l] && s[l] <= '9')
            l++, n = true;
        if (s[l] == '.') {
            l++;
            while ('0' <= s[l] && s[l] <= '9')
                l++, n = true;
            if (!n)
                return false;
        } else if (!n)
            return false;
        if (s[l] == 'e') {
            l++;
            if (s[l] == '+' || s[l] == '-')
                l++;
            n = false;
            while ('0' <= s[l] && s[l] <= '9')
                l++, n = true;
            if (!n)
                return false;
        }
        while (s[l] == ' ')
            l++;
        return !s[l];
    }
};