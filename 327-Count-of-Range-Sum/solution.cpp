class Solution {
    struct point_tree {
        vector<int> tree;
        point_tree(int size) : tree(1 << static_cast<int>(ceil(log2(size))) + 1, 0) {
        }
        void add(int idx) {
            for (idx += tree.size() >> 1; idx; idx >>= 1)
                tree[idx]++;
        }
        int count(int l, int r) {
            int cnt = 0;
            for (l += tree.size() >> 1, r += tree.size() >> 1; l < r; l >>= 1, r >>= 1) {
                if (l & 1)
                    cnt -= tree[l ^ 1];
                if (~r & 1)
                    cnt -= tree[r ^ 1];
            }
            if (l == r)
                cnt += tree[l];
            return cnt;
        }
    };
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long int> sums;
        for (int num: nums)
            sums.push_back(sums.empty() ? num : sums.back() + num);
        auto pre(sums);
        pre.push_back(0);
        sort(begin(pre), end(pre));
        pre.erase(unique(begin(pre), end(pre)), end(pre));
        point_tree pt(pre.size());
        pt.add(distance(begin(pre), lower_bound(begin(pre), end(pre), 0)));
        int cnt = 0;
        for (auto sum: sums) {
            int l = distance(begin(pre), lower_bound(begin(pre), end(pre), sum - upper)),
                r = distance(begin(pre), upper_bound(begin(pre), end(pre), sum - lower)) - 1;
            cnt += pt.count(l, r);
            pt.add(distance(begin(pre), lower_bound(begin(pre), end(pre), sum)));
        }
        return cnt;
    }
};