class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result;
        list<pair<unsigned, int>> l(1, {UINT_MAX, 0});
        for (auto &v: buildings) {
            for (unsigned x; (x = l.front().first) < v[0]; result.push_back({x, l.front().second}))
                l.pop_front();
            if (l.front().first == v[0]) {
                if (l.front().second != v[2])
                    result.push_back({v[0], v[2]});
                l.pop_front();
            } else if (l.front().second < v[2])
                if (!result.empty() && result.back().first == v[0])
                    result.back().second = v[2];
                else
                    result.push_back({v[0], v[2]});
            auto it = l.begin();
            while (it->first < v[1])
                if (it->second <= v[2])
                    it = l.erase(it);
                else
                    ++it;
            if (it->first == v[1])
                it->second = max(it->second, v[2]);
            else if (it->second < v[2])
                l.insert(it, {v[1], v[2]});
        }
        while (1 < l.size()) {
            int x = l.front().first;
            l.pop_front();
            result.push_back({x, l.front().second});
        }
        return result;
    }
};