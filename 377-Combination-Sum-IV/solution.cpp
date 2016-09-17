class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> num(target + 1, 0);
        num[0] = 1;
        for (int i = 0; i <= target; i++)
            if (num[i])
                for (auto n: nums)
                    if (i + n <= target)
                        num[i + n] += num[i];
        return num[target];
    }
};