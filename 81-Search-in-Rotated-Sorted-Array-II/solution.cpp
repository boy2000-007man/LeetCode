class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (int l = 0, r = nums.size() - 1; l <= r; )
            if (nums[l + r >> 1] == target)
                return true;
            else if (nums[l] == nums[r])
                if (nums[l] == target)
                    return true;
                else
                    l++, r--;
            else if (nums[l] < nums[r])
                if (nums[l + r >> 1] < target)
                    l = (l + r >> 1) + 1;
                else
                    r = l + r >> 1;
            else
                if (nums[l + r >> 1] < target)
                    if (nums[l] <= nums[l + r >> 1] || target <= nums[r])
                        l = (l + r >> 1) + 1;
                    else
                        r = l + r >> 1;
                else
                    if (nums[l + r >> 1] <= nums[r] || nums[l] <= target)
                        r = l + r >> 1;
                    else
                        l = (l + r >> 1) + 1;
        return false;
    }
};