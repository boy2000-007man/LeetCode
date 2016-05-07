class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = 0;
        for (int i = 0, p = 0, sum = 0; i < nums.size(); i++)
            if (s <= (sum += nums[i])) {
                while (s <= sum - nums[p])
                    sum -= nums[p++];
                len = min(len ? len : INT_MAX, i - p + 1);
            }
        return len;
    }
};