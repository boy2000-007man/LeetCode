class NumArray {
    vector<int> sum;
public:
    NumArray(vector<int> &nums) : sum(nums) {
        for (int i = 1; i < sum.size(); i++)
            sum[i] += sum[i - 1];
    }

    int sumRange(int i, int j) {
        if (i)
            return sum[j] - sum[i - 1];
        else
            return sum[j];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);