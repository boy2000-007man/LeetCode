class Solution {
public:
    double myPow(double x, int n) {
        if (!n)
            return 1;
        else {
            if (n == INT_MIN) {
                x = 1 / x / x;
                n = -(n >> 1);
            } else if (n < 0) {
                x = 1 / x;
                n = -n;
            }
            double t = 1;
            while (1 < n) {
                if (n & 1)
                    t *= x;
                x *= x;
                n >>= 1;
            }
            return x * t;
        }
    }
};