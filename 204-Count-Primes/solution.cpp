class Solution {
public:
    int countPrimes(int n) {
        int cnt = 2 < n ? 1 : 0;
        vector<bool> bs(n, true);
        int i = 3;
        for (int t; (t = i * i) < n; i += 2)
            if (bs[i]) {
                cnt++;
                do {
                    bs[t] = false;
                } while ((t += i) < n);
            }
        for ( ; i < n; i += 2)
            cnt += bs[i];
        return cnt;
    }
};