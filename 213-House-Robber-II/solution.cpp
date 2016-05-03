class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        else if (nums.size() == 1)
            return nums[0];
        else {
            vector<vector<int>> sum(2, vector<int>(2, 0));
            sum[0][0] = nums[0];
            sum[0][1] = max(sum[0][0], sum[1][1] = nums[1]);
            for (int i = 2; i < nums.size(); i++) {
                sum[0][i & 1] = max(sum[0][~i & 1], sum[0][i & 1] + nums[i]);
                sum[1][i & 1] = max(sum[1][~i & 1], sum[1][i & 1] + nums[i]);
            }
            return max(sum[0][nums.size() & 1], sum[1][~nums.size() & 1]);
        }
    }
};