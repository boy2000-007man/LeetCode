class Solution {
    static bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first || (a.first == b.first && b.second < a.second);
    }
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(begin(envelopes), end(envelopes), cmp);
        vector<int> back;
        for (auto p: envelopes) {
            auto it = lower_bound(begin(back), end(back), p.second);
            if (it != end(back))
                *it = p.second;
            else
                back.insert(it, p.second);
        }
        return back.size();
    }
};