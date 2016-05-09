class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int peak = -1;
        for (int i = 0; i < nums.size() && peak < 0; i++)
            if ((!i || nums[i - 1] < nums[i]) && (i == nums.size() - 1 || nums[i + 1] < nums[i]))
                peak = i;
        return peak;
    }
};