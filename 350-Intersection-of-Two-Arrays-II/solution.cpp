class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> um;
        for (int num: nums1)
            um[num]++;
        for (int num: nums2)
            if (0 < um[num]--)
                result.push_back(num);
        return result;
    }
};