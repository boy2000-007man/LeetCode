class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        for (int r = nums.size() - 1; l < r && nums[r] <= nums[l]; )
            if (nums[l] == nums[r])
                l++;
            else if (nums[l] <= nums[l + r >> 1])
                l = (l + r >> 1) + 1;
            else
                r = l + r >> 1;
        return nums[l];
    }
};