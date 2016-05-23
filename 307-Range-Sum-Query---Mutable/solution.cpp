class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int> &nums) : sums(1 << static_cast<int>(ceil(log2(nums.size()))) + 1, 0) {
        for (int i = 0, o = sums.size() >> 1; i < nums.size(); i++)
            sums[i + o] = nums[i];
        for (int i = sums.size() - 1; 1 < i; i--)
            sums[i >> 1] += sums[i];
    }

    void update(int i, int val) {
        for (int o = val - sums[i += sums.size() >> 1]; i; i >>= 1)
            sums[i] += o;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        for (i += sums.size() >> 1, j += sums.size() >> 1; i < j; i >>= 1, j >>= 1) {
            if (i & 1)
                sum -= sums[i ^ 1];
            if (~j & 1)
                sum -= sums[j ^ 1];
        }
        if (i == j)
            sum += sums[i];
        return sum;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);