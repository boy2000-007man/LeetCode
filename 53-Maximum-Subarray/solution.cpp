class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN,
            sum = 0;
        for (int num: nums) {
            result = max(result, sum += num);
            if (sum < 0)
                sum = 0;
        }
        return result;
    }
};