class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            int &idx = um[target - nums[i]];
            if (idx)
                return {idx - 1, i};
            else
                um[nums[i]] = i + 1;
        }
        return {};
    }
};