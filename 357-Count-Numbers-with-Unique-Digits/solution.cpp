class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int cnt = 1;
        for (int i = 1, t = 9; i <= n && i <= 10; t *= (10 - i++))
            cnt += t;
        return cnt;
    }
};