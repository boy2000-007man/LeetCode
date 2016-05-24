class Solution {
    int div_(unsigned n, int k) {
        return (n + k - 1) / k;
    }
public:
    int maximumGap(vector<int>& nums) {
        int gap = 0,
            l = INT_MAX,
            u = 0;
        for (int num: nums) {
            l = min(l, num);
            u = max(u, num);
        }
        if (l < u) {
            gap = div_(u - l, nums.size() - 1);
            vector<vector<int>> um(nums.size());
            for (int num: nums)
                um[(num - l) / gap].push_back(num);
            u = l;
            for (auto &v: um)
                if (!v.empty()) {
                    int pu = u;
                    l = INT_MAX;
                    for (int num: v) {
                        l = min(l, num);
                        u = max(u, num);
                    }
                    gap = max(gap, l - pu);
                }
        }
        return gap;
    }
};