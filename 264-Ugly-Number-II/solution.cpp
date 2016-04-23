class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> number(1, 1),
                    factor = {2, 3, 5},
                    start(factor.size(), 0);
        while (number.size() < n) {
            int min_num = INT_MAX;
            for (int i = 0, num; i < factor.size(); i++) {
                while ((num = factor[i] * number[start[i]]) <= number.back())
                    start[i]++;
                min_num = min(min_num, num);
            }
            number.push_back(min_num);
        }
        return number.back();
    }
};