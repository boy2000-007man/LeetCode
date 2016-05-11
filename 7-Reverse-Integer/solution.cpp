class Solution {
public:
    int reverse(int x) {
        int result = 0;
        bool n = x < 0;
        if (n)
            if (x == INT_MIN)
                return 0;
            else
                x = -x;
        while (x) {
            int t = result;
            result = 10 * result + x % 10;
            if (result < 0 || result / 10 != t)
                return 0;
            x /= 10;
        }
        return n ? -result : result;
    }
};