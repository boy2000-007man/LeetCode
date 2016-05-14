class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h;
        for (int &l = h = 0, r = citations.size(); l < r; )
            if ((l + r >> 1) + 1 <= citations[citations.size() - 1 - (l + r >> 1)])
                l = (l + r >> 1) + 1;
            else
                r = l + r >> 1;
        return h;
    }
};