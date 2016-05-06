class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> number(amount + 1, -1);
        number[0] = 0;
        queue<int> q;
        for (q.push(0); !q.empty(); q.pop())
            for (int coin: coins)
                if (q.front() + coin <= amount && number[q.front() + coin] == -1) {
                    number[q.front() + coin] = number[q.front()] + 1;
                    q.push(q.front() + coin);
                }
        return number[amount];
    }
};