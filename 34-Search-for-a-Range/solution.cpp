class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range(2);
        for (int &l = range[0] = 0, r = nums.size() - 1; l < r; )
            if (nums[l + r >> 1] < target)
                l = (l + r >> 1) + 1;
            else
                r = l + r >> 1;
        if (nums[range[0]] != target) {
            range[0] = range[1] = -1;
            return range;
        }
        for (int l = range[0], &r = range[1] = nums.size() - 1; l < r; )
            if (nums[l + r + 1 >> 1] <= target)
                l = l + r + 1 >> 1;
            else
                r = l + r - 1 >> 1;
        return range;
    }
};