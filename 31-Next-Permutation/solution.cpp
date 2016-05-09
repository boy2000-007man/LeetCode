class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int loc = nums.size() - 2;
        while (0 <= loc && nums[loc + 1] <= nums[loc])
            loc--;
        if (0 <= loc) {
            int m = loc + 1;
            for (int i = m + 1; i < nums.size(); i++)
                if (nums[loc] < nums[i] && nums[i] < nums[m])
                    m = i;
            swap(nums[loc], nums[m]);
        }
        sort(nums.begin() + max(0, loc + 1), nums.end());
    }
};