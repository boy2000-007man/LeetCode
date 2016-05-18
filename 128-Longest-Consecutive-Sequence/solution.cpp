class Solution {
    int div_(int a, int b) {
        return a < 0 ? (a + 1) / b - 1 : a / b;
    }
    int mod_(int a, int b) {
        return a - b * div_(a, b);
    }
public:
    int longestConsecutive(vector<int>& nums) {
        vector<unordered_map<int, vector<int>>> ums(2);
        for (int num: nums)
            for (int i = 0; i < ums.size(); i++)
                ums[i][div_(num + i * nums.size(), nums.size() << 1)].push_back(num);
        int lcs = 0;
        vector<int> space(nums.size() << 1, nums[0]);
        for (int i = 0; i < ums.size(); i++)
            for (auto &p: ums[i])
                if (lcs < p.second.size()) {
                    for (int num: p.second)
                        space[mod_(num + i * nums.size(), nums.size() << 1)] = num;
                    for (int num: p.second) {
                        int loc = mod_(num + i * nums.size(), nums.size() << 1),
                            len = 1;
                        for (int j = 1; loc + j < space.size() && space[loc + j] - num == j; j++, len++)
                            space[loc + j] = num;
                        for (int j = 1; 0 <= loc - j && num - space[loc - j] == j; j++, len++)
                            space[loc - j] = num;
                        lcs = max(lcs, len);
                    }
                }
        return lcs;
    }
};