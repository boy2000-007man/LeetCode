class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> locs;
        for (int i = 0; i < nums.size(); i++)
            locs.push_back(make_pair(nums[i], i));
        sort(locs.begin(), locs.end());
        for (int i = 1; i < locs.size(); i++)
            if (locs[i - 1].first == locs[i].first && locs[i].second - locs[i - 1].second <= k)
                return true;
        return false;
    }
};