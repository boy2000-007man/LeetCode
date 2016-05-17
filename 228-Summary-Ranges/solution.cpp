class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        stringstream ss;
        for (int i = 0; i < nums.size(); i++)
            if (!i || nums[i - 1] + 1 != nums[i])
                ss << endl << nums[i];
            else if (i == nums.size() - 1 || nums[i] + 1 != nums[i + 1])
                ss << "->" << nums[i];
        vector<string> result;
        for (string s; ss >> s; result.push_back(s));
        return result;
    }
};