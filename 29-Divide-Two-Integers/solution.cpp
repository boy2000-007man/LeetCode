class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        else if (divisor == INT_MIN)
            return dividend == INT_MIN;
        else {
            int sign = 1;
            if (0 < dividend)
                dividend = -dividend, sign *= -1;
            if (divisor < 0)
                divisor = -divisor, sign *= -1;
            int result = 0,
                k = 1;
            while (divisor < INT_MAX >> 1)
                divisor <<= 1, k <<= 1;
            while (dividend < 0 && k) {
                while (dividend <= -divisor)
                    dividend += divisor, result -= k;
                divisor >>= 1;
                k >>= 1;
            }
            return sign * result;
        }
    }
};