class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> loc(26, -1);
        for (int i = 0; i < s.size(); i++) {
            auto &l = loc[s[i] - 'a'];
            if (l == -1)
                l = i;
            else
                l = INT_MAX;
        }
        int res = INT_MAX;
        for (auto l: loc)
            if (l != -1)
                res = min(res, l);
        return res != INT_MAX ? res : -1;
    }
};