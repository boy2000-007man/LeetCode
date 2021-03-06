class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        vector<int> loc;
        for (int i = 0, cnt; i < nums.size(); i++)
            if (!i || nums[i - 1] != nums[i]) {
                nums[loc.size()] = nums[i];
                loc.push_back(loc.size());
                cnt = 1;
            } else if (++cnt <= 4) {
                nums[loc.size()] = nums[i];
                loc.push_back(loc.back());
            }
        nums.resize(loc.size());
        vector<pair<int, int>> sum2;
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                sum2.push_back(make_pair(nums[i] + nums[j], i * nums.size() + j));
        sort(sum2.begin(), sum2.end());
        unordered_map<int, int> um;
        for (int l = 0, r = sum2.size() - 1; l < r; l++) {
            while (l < r && target < sum2[l].first + sum2[r].first)
                r--;
            for (int i = r; l < i && target == sum2[l].first + sum2[i].first; i--) {
                vector<int> abcd = {static_cast<int>(sum2[l].second / nums.size()), static_cast<int>(sum2[l].second % nums.size()), static_cast<int>(sum2[i].second / nums.size()), static_cast<int>(sum2[i].second % nums.size())};
                sort(abcd.begin(), abcd.end());
                if (unique(abcd.begin(), abcd.end()) == abcd.end()) {
                    int order = 0;
                    for (int a: abcd)
                        order = order * nums.size() + loc[a];
                    if (!um[order]++) {
                        for (int &a: abcd)
                            a = nums[a];
                        result.push_back(abcd);
                    }
                }
            }
        }
        return result;
    }
};