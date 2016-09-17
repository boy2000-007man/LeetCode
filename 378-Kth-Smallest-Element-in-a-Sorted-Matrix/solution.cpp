class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> nums;
        for (auto &v: matrix)
            for (auto n: v)
                nums.push_back(n);
        nth_element(nums.begin(), nums.begin() + --k, nums.end());
        return nums[k];
    }
};