class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,
            r = nums.size() - 1;
        while (l < r)
            if (nums[l + r >> 1] == target)
                l = r = l + r >> 1;
            else if (nums[l] < nums[r])
                if (nums[l + r >> 1] < target)
                    l = (l + r >> 1) + 1;
                else
                    r = l + r >> 1;
            else
                if (nums[l + r >> 1] < target)
                    if (nums[l] < nums[l + r >> 1] || target <= nums[r])
                        l = (l + r >> 1) + 1;
                    else
                        r = l + r >> 1;
                else
                    if (nums[l + r >> 1] < nums[r] || nums[r] < target)
                        r = l + r >> 1;
                    else
                        l = (l + r >> 1) + 1;
        if (nums[l] == target)
            return l;
        else
            return -1;
    }
};