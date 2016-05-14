class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result(1);
        for (int i = 0, next = 1; i < nums.size(); i = next++) {
            while (next < nums.size() && nums[next - 1] == nums[next])
                next++;
            for (int j = 0, size = result.size(); j < size; j++) {
                vector<int> subset(result[j]);
                for (int k = i; k < next; k++) {
                    subset.push_back(nums[k]);
                    result.push_back(subset);
                }
            }
        }
        return result;
    }
};