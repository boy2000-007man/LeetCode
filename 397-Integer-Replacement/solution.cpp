class Solution {
public:
    int integerReplacement(unsigned n) {
        if (n == 1)
            return 0;
        else if (n & 1)
            return min(integerReplacement(n >> 1), integerReplacement(n + 1 >> 1)) + 2;
        else
            return integerReplacement(n >> 1) + 1;
    }
};