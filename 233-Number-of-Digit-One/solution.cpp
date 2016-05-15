class Solution {
public:
    int countDigitOne(int n) {
        int cnt = 0;
        for (long long int i = 1; i <= n; i *= 10) {
            cnt += n / i / 10 * i;
            switch (n / i % 10) {
                case 1:cnt += n % i + 1;
                case 0:break;
                default:cnt += i;
            }
        }
        return cnt;
    }
};