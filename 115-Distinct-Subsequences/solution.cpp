class Solution {
public:
    int numDistinct(string s, string t) {
        if (t.empty())
            return 1;
        vector<vector<int>> c2ls(256);
        for (int i = 0; s[i]; i++)
            c2ls[s[i]].push_back(i);
        vector<vector<int>> num(t.length());
        for (int i = 0; t[i]; i++)
            if (!i)
                for (int l: c2ls[t[i]])
                    num[i].push_back(1);
            else {
                int j = 0,
                    n = 0;
                for (int l: c2ls[t[i]]) {
                    while (j < num[i - 1].size() && c2ls[t[i - 1]][j] < l)
                        n += num[i - 1][j++];
                    num[i].push_back(n);
                }
            }
        int result = 0;
        for (int n: num.back())
            result += n;
        return result;
    }
};