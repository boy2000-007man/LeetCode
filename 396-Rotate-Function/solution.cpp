class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int F = 0, sum = 0;
        for (int i = 0; i < A.size(); i++) {
            F += i * A[i];
            sum += A[i];
        }
        int maximum = F;
        for (int i = 1; i < A.size(); i++)
            maximum = max(maximum, F += sum - A.size() * A[A.size() - i]);
        return maximum;
    }
};