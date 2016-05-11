class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        vector<int> cnt(nums.size() + 1, 0);
        int len = 0;
        for (int num: nums)
            if (!um[num]++)
                nums[len++] = num;
        nums.resize(len);
        for (int num: nums)
            cnt[um[num]]++;
        int t;
        for (int &i = t = cnt.size() - 1, n = 0; 0 <= i && n < k; i--)
            n += cnt[i];
        len = 0;
        for (int num: nums)
            if (t < um[num])
                nums[len++] = num;
        nums.resize(k);
        return nums;
    }
};