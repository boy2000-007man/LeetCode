class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result;
        vector<vector<int>> loc(26);
        for (int i = 0; s[i]; i++)
            loc[s[i] - 'a'].push_back(i);
        for (auto &v: loc)
            reverse(v.begin(), v.end());
        while (1) {
            int m = INT_MAX;
            for (auto &v: loc)
                if (!v.empty() && v[0] < m)
                    m = v[0];
            if (m == INT_MAX)
                break;
            bool selected = false;
            for (auto &v: loc)
                if (selected)
                    while (!v.empty() && v.back() <= m)
                        v.pop_back();
                else
                    if (!v.empty() && v.back() <= m) {
                        result += s[m = v.back()];
                        v.clear();
                        selected = true;
                    }
        }
        return result;
    }
};