class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1},
            dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (board[i][j] & 1)
                    for (int k = 0; k < 8; k++)
                        if (0 <= i + dx[k] && i + dx[k] < board.size() && 0 <= j + dy[k] && j + dy[k] < board[i].size())
                            board[i + dx[k]][j + dy[k]] += 1 << 1;
        for (auto &v: board)
            for (int &l: v)
                l = (l >> 1 == 3) || (l & 1 && l >> 1 == 2);
    }
};