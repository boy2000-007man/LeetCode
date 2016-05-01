class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int len1 = num1.length(),
            len2 = num2.length();
        vector<int> res(len1 + len2, 0);
        for (int i = 0; num1[i]; i++)
            for (int j = 0; num2[j]; j++)
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        for (int i = res.size() - 1; i; i--) {
            res[i - 1] += res[i] / 10;
            res[i] %= 10;
        }
        stringstream ss;
        for (int i = !res[0]; i < res.size(); i++)
            ss << res[i];
        return ss.str();
    }
};