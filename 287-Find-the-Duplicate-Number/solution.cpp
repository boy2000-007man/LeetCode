class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int dup;
        for (int &l = dup = 1, r = nums.size() - 1; l < r; ) {
            int m = l + r >> 1,
                cnt = 0;
            for (int num: nums)
                cnt += l <= num && num <= m;
            if (cnt <= m - l + 1)
                l = m + 1;
            else
                r = m;
        }
        return dup;
    }
};