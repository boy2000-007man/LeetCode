class Solution {
    int s2i(const string &s) {
        return ((s[0] - 'A') * 26 + (s[1] - 'A')) * 26 + (s[2] - 'A');
    }
    string i2s(int i) {
        return {(char)(i / 26 / 26 + 'A'), (char)(i / 26 % 26 + 'A'), (char)(i % 26 + 'A')};
    }
    bool search(vector<vector<pair<int, bool>>> &next, vector<int> &route, int n) {
        if (n == route.size())
            return true;
        for (auto &p: next[route[n - 1]])
            if (!p.second) {
                route[n] = p.first;
                p.second = true;
                if (search(next, route, n + 1))
                    return true;
                p.second = false;
            }
        return false;
    }
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<vector<pair<int, bool>>> next(26 * 26 * 26);
        for (auto &t: tickets)
            next[s2i(t.first)].push_back(make_pair(s2i(t.second), false));
        for (auto &v: next)
            sort(v.begin(), v.end());
        vector<int> route(tickets.size() + 1, s2i("JFK"));
        search(next, route, 1);
        vector<string> result;
        for (int a: route)
            result.push_back(i2s(a));
        return result;
    }
};