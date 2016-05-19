class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        for (int num: nums1)
            um[num] = 1;
        for (int num: nums2)
            if (um[num])
                um[num] = 2;
        vector<int> result;
        for (auto &p: um)
            if (p.second == 2)
                result.push_back(p.first);
        return result;
    }
};