class Solution {
public:
    bool isPowerOfThree(int n) {
        return (0 < n) && !(1162261467 % n);
    }
};