class Solution {
    int mask[3][9];
    vector<vector<int>> loc;
    bool search(vector<vector<char>> &board, int depth = 0) {
        if (depth == loc.size())
            return true;
        for (int i = loc[depth][1], j = loc[depth][2], k = 1, t = mask[0][i] | mask[1][j] | mask[2][i / 3 * 3 + j / 3], m; k <= 9; k++)
            if (!(t & (m = 1 << k))) {
                board[i][j] = '0' + k;
                mask[0][i] |= m;
                mask[1][j] |= m;
                mask[2][i / 3 * 3 + j / 3] |= m;
                if (search(board, depth + 1))
                    return true;
                mask[0][i] &= ~m;
                mask[1][j] &= ~m;
                mask[2][i / 3 * 3 + j / 3] &= ~m;
            }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(mask, 0, sizeof(mask));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int m = 1 << board[i][j] - '0';
                    mask[0][i] |= m;
                    mask[1][j] |= m;
                    mask[2][i / 3 * 3 + j / 3] |= m;
                }
        loc.clear();
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.') {
                    int cnt = 0;
                    for (int t = mask[0][i] | mask[1][j] | mask[2][i / 3 * 3 + j / 3]; t; t >>= 1)
                        if (t & 1)
                            cnt++;
                    loc.push_back({-cnt, i, j});
                }
        sort(loc.begin(), loc.end());
        search(board);
    }
};