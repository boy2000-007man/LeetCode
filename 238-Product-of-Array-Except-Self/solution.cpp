class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums);
        for (int i = result.size() - 2; 0 < i; i--)
            result[i] *= result[i + 1];
        for (int i = 0, p = 1; i < result.size(); p *= nums[i++])
            if (i + 1 < result.size())
                result[i] = p * result[i + 1];
            else
                result[i] = p;
        return result;
    }
};