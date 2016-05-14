class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        for (unsigned i = 1; m + i <= n; i <<= 1)
            m &= ~i;
        return m;
    }
};