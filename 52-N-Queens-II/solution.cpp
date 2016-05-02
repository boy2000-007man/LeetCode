class Solution {
    int search(vector<int> &stk, int n) {
        if (n == stk.size())
            return 1;
        else {
            int num = 0;
            for (int &i = stk[n] = 0; i < stk.size(); i++) {
                bool valid = true;
                for (int j = 0; j < n; j++)
                    if (i == stk[j] || abs(i - stk[j]) == n - j)
                        valid = false;
                if (valid)
                    num += search(stk, n + 1);
            }
            return num;
        }
    }
public:
    int totalNQueens(int n) {
        vector<int> stk(n);
        return search(stk, 0);
    }
};