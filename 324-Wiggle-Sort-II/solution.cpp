class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int m = nums.size() - 1 >> 1;
        nth_element(begin(nums), begin(nums) + m, end(nums));
        int e = nums[m];
        for (int i = 0, loc = 0; i <= m; i++)
            if (nums[i] == e)
                swap(nums[i], nums[loc++]);
        for (int i = m; i; i--)
            swap(nums[i], nums[i << 1]);
        for (int i = (nums.size() & -2) - 1, loc = i; 1 <= i; i -= 2)
            if (nums[i] == e) {
                swap(nums[i], nums[loc]);
                loc -= 2;
            }
    }
};