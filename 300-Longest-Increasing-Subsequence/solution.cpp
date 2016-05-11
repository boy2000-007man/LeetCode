class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> end;
        for (int num: nums) {
            auto it = lower_bound(end.begin(), end.end(), num);
            if (it == end.end())
                end.push_back(num);
            else
                *it = num;
        }
        return end.size();
    }
};