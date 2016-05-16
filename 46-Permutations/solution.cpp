class Solution {
    void search(vector<vector<int>> &result, vector<int> &nums, vector<int> &permutation, int k) {
        if (k < nums.size())
            for (int num: nums) {
                bool distinct = true;
                for (int j = 0; j < k && distinct; j++)
                    distinct = num != permutation[j];
                if (distinct) {
                    permutation[k] = num;
                    search(result, nums, permutation, k + 1);
                }
            }
        else
            result.push_back(permutation);
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> permutation(nums.size());
        search(result, nums, permutation, 0);
        return result;
    }
};