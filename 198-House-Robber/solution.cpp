class Solution {
public:
    int rob(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (0 <= i - 2)
                nums[i] += nums[i - 2];
            nums[i] = max(nums[i], nums[i - 1]);
        }
        return nums.empty() ? 0 : nums.back();
    }
};