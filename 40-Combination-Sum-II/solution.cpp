class Solution {
    void search(vector<vector<int>> &result, vector<int> &candidates, vector<int> &combination, int target, int k) {
        if (!target)
            result.push_back(combination);
        else if (k < candidates.size() && candidates[k] <= target) {
            int next = k + 1;
            while (next < candidates.size() && candidates[next - 1] == candidates[next])
                next++;
            int end = k;
            while (end < next && candidates[k] * (end - k + 1) <= target)
                combination.push_back(candidates[end++]);
            while (k <= --end) {
                search(result, candidates, combination, target - candidates[k] * (end - k + 1), next);
                combination.pop_back();
            }
            search(result, candidates, combination, target, next);
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        search(result, candidates, combination, target, 0);
        return result;
    }
};