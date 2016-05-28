class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> cnt(n, 0);
        vector<vector<int>> e(n);
        for (auto &p: edges) {
            cnt[p.first]++;
            cnt[p.second]++;
            e[p.first].push_back(p.second);
            e[p.second].push_back(p.first);
        }
        vector<int> v;
        for (int i = 0; i < cnt.size(); i++)
            if (cnt[i] == 1)
                v.push_back(i);
        while (2 < n) {
            vector<int> next;
            for (int i: v) {
                for (int j: e[i])
                    if (--cnt[j] == 1)
                        next.push_back(j);
                n--;
            }
            v.swap(next);
        }
        return v.empty() ? vector<int>(1, 0) : v;
    }
};