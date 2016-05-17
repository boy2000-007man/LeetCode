class Solution {
public:
    bool isPowerOfFour(int num) {
        return (0 < num) && !((1 << 30) % num) && (num & 0x55555555);
    }
};