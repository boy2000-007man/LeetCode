class Solution {
    void search(vector<vector<int>> &result, vector<int> &combination, int k, int n) {
        if (k < combination.size())
            for (int &i = combination[k] = (k ? combination[k - 1] + 1 : 1); i <= 9 && i <= n; i++)
                search(result, combination, k + 1, n - i);
        else if (!n)
            result.push_back(combination);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination(k);
        search(result, combination, 0, n);
        return result;
    }
};