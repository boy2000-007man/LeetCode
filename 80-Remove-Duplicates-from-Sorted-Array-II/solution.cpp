class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        pair<int, int> cnt(0, 0);
        for (int &num: nums)
            if (num != cnt.first) {
                cnt = make_pair(num, 1);
                swap(num, nums[len++]);
            } else if (++cnt.second <= 2)
                swap(num, nums[len++]);
        return len;
    }
};