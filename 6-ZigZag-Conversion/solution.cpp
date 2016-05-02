class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string result;
        int len = s.length();
        for (int i = 0; i < len; i += numRows - 1 << 1)
            result += s[i];
        for (int i = 1; i < numRows - 1; i++)
            for (int j = i, offset = numRows - j - 1 << 1; j < len; j += numRows - 1 << 1) {
                result += s[j];
                if (j + offset < len)
                    result += s[j + offset];
            }
        for (int i = numRows - 1; i < len; i += numRows - 1 << 1)
            result += s[i];
        return result;
    }
};