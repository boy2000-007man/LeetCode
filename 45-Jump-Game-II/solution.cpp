class Solution {
public:
    int jump(vector<int>& nums) {
        int n = 0;
        for (int i = 0, idx = 0, max_idx = 0; idx < nums.size() - 1; i++) {
            if (idx < i) {
                idx = max_idx;
                n++;
            }
            max_idx = max(max_idx, i + nums[i]);
        }
        return n;
    }
};