class Solution {
    struct segment_tree {
        vector<pair<int, int>> tree;
        segment_tree(int size) : tree(2 << (int)(ceil(log2(max(1, size)))), make_pair(-1, -1)) {
            tree[0] = make_pair(0, size);
        }
        pair<int, int> &search(int m) {
            int c = 0;
            for (int l = 0, r = tree.size() >> 1; tree[c].first < 0; )
                if (m < l + r >> 1) {
                    r = l + r >> 1;
                    c = (c << 1) + 1;
                } else {
                    l = l + r >> 1;
                    c = c + 1 << 1;
                }
            return tree[c];
        }
        void modify(int c, int l, int r, const pair<int, int> &p) {
            if (p.first <= l && r <= p.second)
                tree[c] = p;
            else {
                tree[c].first = -1;
                int m = l + r >> 1;
                if (p.first < m)
                    modify((c << 1) + 1, l, m, p);
                if (m < p.second)
                    modify(c + 1 << 1, m, r, p);
            }
        }
    };
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> loc;
        for (int i = 0; i < heights.size(); i++)
            loc.push_back(make_pair(heights[i], i));
        sort(loc.begin(), loc.end());
        int area = 0;
        segment_tree st(heights.size());
        for (auto &l: loc) {
            auto p = st.search(l.second);
            area = max(area, (p.second - p.first) * l.first);
            if (p.first < l.second)
                st.modify(0, 0, st.tree.size() >> 1, make_pair(p.first, l.second));
            if (l.second + 1 < p.second)
                st.modify(0, 0, st.tree.size() >> 1, make_pair(l.second + 1, p.second));
        }
        return area;
    }
};