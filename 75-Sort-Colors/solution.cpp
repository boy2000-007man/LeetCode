class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> n(3, 0);
        for (int num: nums)
            n[num]++;
        nums.clear();
        for (int i = 0; i < n.size(); i++)
            for (int j = 0; j < n[i]; j++)
                nums.push_back(i);
    }
};