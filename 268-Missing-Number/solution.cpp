class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int &num: nums)
            while (num < nums.size() && &num != &nums[num])
                swap(num, nums[num]);
        for (int i = 0; i < nums.size(); i++)
            if (i != nums[i])
                return i;
        return nums.size();
    }
};