class Solution {
public:
    int countPrimes(int n) {
        int cnt = 2 < n ? 1 : 0;
        bool bs[n];
        memset(bs, 0xff, sizeof(bs));
        int i = 3;
        for (int t; (t = i * i) < n; i += 2)
            if (bs[i]) {
                cnt++;
                do {
                    bs[t] = false;
                } while ((t += i) < n);
            }
        for ( ; i < n; i += 2)
            if (bs[i])
                cnt++;
        return cnt;
    }
};