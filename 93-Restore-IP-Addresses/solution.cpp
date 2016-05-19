class Solution {
    bool valid(const string &s) {
        if (s[0] == '0' && s[1])
            return false;
        int num = 0;
        for (char c: s)
            if (255 < (num = 10 * num + (c - '0')))
                return false;
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        for (int i = 1, len = s.length(); i <= 3 && i < len && valid(s.substr(0, i)); i++)
            for (int j = 1; j <= 3 && i + j < len && valid(s.substr(i, j)); j++)
                for (int k = 1; k <= 3 && i + j + k < len && valid(s.substr(i + j, k)); k++)
                    if (valid(s.substr(i + j + k)))
                        result.push_back(s.substr(0, i) + '.' + s.substr(i, j) + '.' + s.substr(i + j, k) + '.' + s.substr(i + j + k));
        return result;
    }
};