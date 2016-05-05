class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        else {
            for (int k = 1000000000; 10 <= k; k /= 10)
                if (k <= x) {
                    x %= k + 1;
                    if (k <= x || x % 10)
                        return false;
                    x /= 10;
                }
            return true;
        }
    }
};