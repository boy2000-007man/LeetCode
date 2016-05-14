class Solution {
    struct point_tree {
        vector<int> number;
        point_tree(int size) : number(1 << static_cast<int>(ceil(log2(size))) + 1, 0) {
        }
        int search(int i) {
            int cnt = 0;
            for (i += number.size() >> 1; 1 < i; i >>= 1) {
                if (~i & 1)
                    cnt += number[i ^ 1];
                number[i]++;
            }
            return cnt;
        }
    };
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> loc;
        for (int i = 0; i < nums.size(); i++)
            loc.push_back(make_pair(nums[i], i));
        sort(loc.begin(), loc.end());
        point_tree pt(nums.size());
        for (auto &p: loc)
            nums[p.second] = pt.search(p.second);
        return nums;
    }
};