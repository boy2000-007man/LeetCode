class Solution {
    int roman(char c) {
        switch (c) {
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
            default:return 0;
        }
    }
public:
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; s[i]; i++)
            if (roman(s[i]) < roman(s[i + 1]))
                result -= roman(s[i]);
            else
                result += roman(s[i]);
        return result;
    }
};