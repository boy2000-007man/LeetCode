class Solution {
public:
    int mySqrt(int x) {
        static int SQRT_INT_MAX = 46340;
        if (x < 0)
            return INT_MIN;
        else if (pow(SQRT_INT_MAX, 2) <= x)
            return SQRT_INT_MAX;
        int l = 0;
        for (int r = SQRT_INT_MAX; 1 < r - l; )
            if (pow(l + r >> 1, 2) <= x)
                l = l + r >> 1;
            else
                r = l + r >> 1;
        return l;
    }
};