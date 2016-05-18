class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for (int num: nums)
            if (num != val)
                nums[len++] = num;
        return len;
    }
};