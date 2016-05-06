class Solution {
    int change(vector<pair<bool, int>> &number, vector<int> &coins, int amount) {
        if (!number[amount].first) {
            for (int coin: coins)
                if (coin <= amount && change(number, coins, amount - coin) != -1)
                    number[amount].second = min(number[amount].second, number[amount - coin].second + 1);
            if (number[amount].second == INT_MAX)
                number[amount].second = -1;
            number[amount].first = !number[amount].first;
        }
        return number[amount].second;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<pair<bool, int>> number(amount + 1, make_pair(false, INT_MAX));
        number[0] = make_pair(true, 0);
        return change(number, coins, amount);
    }
};