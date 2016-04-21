class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        list<pair<int, int>> edges_(0);
        for (auto &edge: edges)
            edges_.push_back(edge);
        vector<bool> is_root(n, true);
        while (2 < n) {
            vector<int> k(is_root.size(), 0);
            for (auto &edge: edges_) {
                k[edge.first]++;
                k[edge.second]++;
            }
            for (auto it = edges_.begin(); it != edges_.end(); )
                if (k[it->first] != 1 && k[it->second] != 1)
                    ++it;
                else {
                    if (k[it->first] == 1) {
                        is_root[it->first] = false;
                        n--;
                    }
                    if (k[it->second] == 1) {
                        is_root[it->second] = false;
                        n--;
                    }
                    it = edges_.erase(it);
                }
        }
        vector<int> root(0);
        for (int i = 0; root.size() < n; i++)
            if (is_root[i])
                root.push_back(i);
        return root;
    }
};