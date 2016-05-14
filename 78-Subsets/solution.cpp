class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result(1);
        for (int num: nums)
            for (int i = 0, size = result.size(); i < size; i++) {
                vector<int> subset(result[i]);
                subset.push_back(num);
                result.push_back(subset);
            }
        return result;
    }
};