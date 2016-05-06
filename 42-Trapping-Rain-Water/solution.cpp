class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        vector<pair<int, int>> h;
        for (int i = 0; i < height.size(); i++) {
            for (int bottom = 0; !h.empty(); h.pop_back()) {
                water += (min(h.back().second, height[i]) - bottom) * (i - h.back().first - 1);
                if (height[i] < (bottom = h.back().second))
                    break;
            }
            h.push_back(make_pair(i, height[i]));
        }
        return water;
    }
};