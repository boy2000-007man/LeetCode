class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1;
        for (int r = 46340, m; l < r; )
            if ((m = l + r >> 1) * m < num)
                l = m + 1;
            else
                r = m;
        return l * l == num;
    }
};