class Solution {
public:
    int numSquares(int n) {
        vector<pair<int, int>> square(0);
        for (int i = 1; i * i <= n; i++)
            square.push_back(make_pair(i * i, 0));
        int min_num = INT_MAX,
            num = 0;
        square.back().second = n / square.back().first;
        n -= square.back().first * square.back().second;
        num += square.back().second;
        for (int i = square.size() - 1; i < square.size(); )
            if (!n || square[i].second < 0) {
                if (!n)
                    min_num = min(min_num, num);
                n += square[i].first * square[i].second;
                num -= square[i].second;
                if (++i < square.size()) {
                    n += square[i].first;
                    square[i].second--;
                    num--;
                }
            } else {
                square[i - 1].second = n / square[i - 1].first;
                n -= square[i - 1].first * square[i - 1].second;
                num += square[i - 1].second;
                if (num < min_num)
                    i--;
                else {
                    n += square[i - 1].first * square[i - 1].second;
                    num -= square[i - 1].second;
                    n += square[i].first * square[i].second;
                    num -= square[i].second;
                    if (++i < square.size()) {
                        n += square[i].first;
                        square[i].second--;
                        num--;
                    }
                }
            }
        return min_num;
    }
};