class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0, loc; i < nums.size(); i++)
            if (0 < nums[i] && nums[i] <= nums.size()) {
                swap(nums[i], nums[loc = nums[i] - 1]);
                if (i < loc)
                    i--;
            }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1)
                return i + 1;
        return nums.size() + 1;
    }
};