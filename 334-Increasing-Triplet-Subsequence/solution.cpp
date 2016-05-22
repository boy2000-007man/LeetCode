class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> seq;
        for (int num: nums) {
            auto it = lower_bound(begin(seq), end(seq), num);
            if (it != end(seq))
                *it = num;
            else {
                seq.push_back(num);
                if (3 <= seq.size())
                    return true;
            }
        }
        return false;
    }
};