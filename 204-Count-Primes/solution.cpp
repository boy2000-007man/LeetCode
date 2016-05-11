class Solution {
public:
    int countPrimes(int n) {
        if (n < 3)
            return 0;
        vector<int> primes(1, 2);
        for (int k = 3; k < n; k += 2) {
            bool p = true;
            for (int i = 0; i < primes.size() && p && primes[i] * primes[i] <= k; i++)
                p = k % primes[i];
            if (p)
                primes.push_back(k);
        }
        return primes.size();
    }
};