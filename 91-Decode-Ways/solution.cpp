class Solution {
public:
    int numDecodings(string s) {
        vector<int> num(s.length(), 0);
        for (int i = 0; s[i]; i++) {
            if (s[i] != '0')
                num[i] += i ? num[i - 1] : 1;
            if (i && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')))
                num[i] += 1 < i ? num[i - 2] : 1;
        }
        return num.empty() ? 0 : num.back();
    }
};