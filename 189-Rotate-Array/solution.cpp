class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n) {
            k %= n;
            reverse(begin(nums), next(begin(nums), n - k));
            reverse(next(begin(nums), n - k), end(nums));
            reverse(begin(nums), end(nums));
        }
    }
};