class Solution {
    string add(string a, string b) {
        string result;
        reverse(begin(a), end(a));
        reverse(begin(b), end(b));
        for (int i = 0, t = 0; i < a.length() || i < b.length() || t; i++) {
            if (i < a.length())
                t += a[i] - '0';
            if (i < b.length())
                t += b[i] - '0';
            result += static_cast<char>('0' + t % 10);
            t /= 10;
        }
        reverse(begin(result), end(result));
        return result;
    }
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1, len = num.length(); i <= len / 3 && (i == 1 || num[0] != '0'); i++)
            for (int j = 1; i + j + max(i, j) <= len && (j == 1 || num[i] != '0'); j++) {
                string a = num.substr(0, i),
                       b = num.substr(i, j);
                int loc = i + j;
                for (string s = add(a, b); num.substr(loc, s.length()) == s; s = add(a, b)) {
                    a = b;
                    if ((loc += (b = s).length()) == len)
                        return true;
                }
            }
        return false;
    }
};