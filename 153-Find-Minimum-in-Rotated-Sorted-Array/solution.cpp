class Solution {
public:
    int findMin(vector<int>& nums) {
        for (int l = 0, r = nums.size() - 1; ; )
            if (nums[l] <= nums[r])
                return nums[l];
            else
                if (nums[l] <= nums[l + r >> 1])
                    l = (l + r >> 1) + 1;
                else
                    r = l + r >> 1;
    }
};