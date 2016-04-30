class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        for (int i = 1, j = 1; i < result.size(); i++) {
            if (j << 1 <= i)
                j <<= 1;
            result[i] = result[i ^ j] + 1;
        }
        return result;
    }
};