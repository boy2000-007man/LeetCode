class Solution {
    void search(vector<vector<int>> &result, vector<int> &nums, vector<int> &permutation, int k) {
        if (k < nums.size())
            for (int &i = permutation[k] = (!k || nums[k - 1] != nums[k] ? 0 : permutation[k - 1] + 1); i < nums.size(); i++) {
                bool unique = true;
                for (int j = 0; j < k && unique; j++)
                    unique = i != permutation[j];
                if (unique)
                    search(result, nums, permutation, k + 1);
            }
        else {
            result.push_back(vector<int>(nums.size()));
            for (int i = 0; i < permutation.size(); i++)
                result.back()[permutation[i]] = nums[i];
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> permutation(nums.size());
        sort(nums.begin(), nums.end());
        search(result, nums, permutation, 0);
        return result;
    }
};