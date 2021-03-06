class Solution {
    bool search(vector<pair<int, int>> &v, int l, int num, int k, unsigned t) {
        for (int i = v.size() - 1; 0 <= i && l - v[i].first <= k; i--)
            if ((num < v[i].second ? v[i].second - num : num - v[i].second) <= t)
                return true;
        v.push_back(make_pair(l, num));
        return false;
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (0 <= t) {
            unordered_map<int, vector<pair<int, int>>> um;
            for (unsigned i = 0, bin = (t << 1) + 1; i < nums.size(); i++) {
                int n = nums[i] / bin,
                    m = nums[i] % bin;
                if (search(um[n], i, nums[i], k, t)
                || (m < t && search(um[n - 1], i, nums[i], k, t))
                || (t < m && search(um[n + 1], i, nums[i], k, t)))
                    return true;
            }
        }
        return false;
    }
};