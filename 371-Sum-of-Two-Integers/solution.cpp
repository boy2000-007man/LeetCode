class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0,
            and_ = a & b,
            xor_ = a ^ b;
        for (int mask = 1, t = 0; mask; mask <<= 1) {
            sum |= (xor_ ^ t) & mask;
            t = (and_ & mask) || (xor_ & t) ? mask << 1 : 0;
        }
        return sum;
    }
};