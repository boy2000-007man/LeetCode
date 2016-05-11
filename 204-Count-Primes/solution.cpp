class Solution {
public:
    int countPrimes(int n) {
        int cnt = 2 < n ? 1 : 0;
        vector<bool> bs(n, true);
        for (int i = 3, t; (t = i * i) < n; i += 2)
            if (bs[i])
                do {
                    bs[t] = false;
                } while ((t += i) < n);
        for (int i = 3; i < n; i += 2)
            cnt += bs[i];
        return cnt;
    }
};