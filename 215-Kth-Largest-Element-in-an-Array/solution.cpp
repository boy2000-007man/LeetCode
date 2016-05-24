class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(begin(nums), begin(nums) + --k, end(nums), greater<int>());
        return nums[k];
    }
};