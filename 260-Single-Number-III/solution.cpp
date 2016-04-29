class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num: nums)
            res ^= num;
        for (int i = 0; res >> i; i++)
            if (res & (1 << i))
                res = 1 << i;
        int a = 0, b = 0;
        for (int num: nums)
            if (num & res)
                a ^= num;
            else
                b ^= num;
        return {a, b};
    }
};