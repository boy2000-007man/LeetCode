class Solution {
public:
    int integerBreak(int n) {
        if (3 < n)
            switch (n % 3) {
                case 0:return pow(3, n / 3);
                case 1:return pow(3, (n - 4) / 3) * 4;
                case 2:return pow(3, n / 3) * 2;
            }
        return n - 1;
    }
};