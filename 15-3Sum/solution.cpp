class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(begin(nums), end(nums));
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1, k = nums.size() - 1; j < k; j++) {
                while (j < k && 0 < nums[i] + nums[j] + nums[k])
                    k--;
                if (j < k && !(nums[i] + nums[j] + nums[k]))
                    result.push_back({nums[i], nums[j], nums[k]});
                while (j < k && nums[j + 1] == nums[j])
                    j++;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
                i++;
        }
        return result;
    }
};