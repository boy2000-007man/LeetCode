class Solution {
public:
    int myAtoi(string str) {
        int i = 0,
            l = 0;
        bool n = false;
        while (str[l] == ' ')
            l++;
        if (str[l] == '+' || str[l] == '-') {
            n = str[l] == '-';
            l++;
        }
        while ('0' <= str[l] && str[l] <= '9') {
            int t = i;
            i = 10 * i + (str[l] - '0');
            if (i < 0 || i / 10 != t)
                return n ? INT_MIN : INT_MAX;
            l++;
        }
        return n ? -i : i;
    }
};