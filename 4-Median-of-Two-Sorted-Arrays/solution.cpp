class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() < nums1.size())
            nums1.swap(nums2);
        if (nums1.empty())
            if (nums2.empty())
                return 0;
            else
                return (nums2[nums2.size() - 1 >> 1] + nums2[nums2.size() >> 1]) / 2.0;
        else if (nums1.size() < nums2.size() && nums1.back() <= nums2[nums2.size() - nums1.size() - 1 >> 1])
            return (nums2[nums2.size() - nums1.size() - 1 >> 1] + nums2[nums2.size() - nums1.size() >> 1]) / 2.0;
        else if (nums1.back() <= nums2[nums2.size() - nums1.size() >> 1]
        && (nums1.size() == nums2.size() || nums2[nums2.size() - nums1.size() - 1 >> 1] <= nums1.back()))
            return (nums1.back() + nums2[nums2.size() - nums1.size() >> 1]) / 2.0;
        else if (nums1.size() < nums2.size() && nums2[nums2.size() + nums1.size() >> 1] <= nums1[0])
            return (nums2[nums2.size() + nums1.size() - 1 >> 1] + nums2[nums2.size() + nums1.size() >> 1]) / 2.0;
        else if (nums2[nums2.size() + nums1.size() - 1 >> 1] <= nums1[0]
        && (nums1.size() == nums2.size() || nums1[0] <= nums2[nums2.size() + nums1.size() >> 1]))
            return (nums2[nums2.size() + nums1.size() - 1 >> 1] + nums1[0]) / 2.0;
        else if (nums1.size() + nums2.size() & 1)
            for (int l = 0, r = nums1.size() - 1; ; ) {
                int m1 = l + r >> 1,
                    m2 = (nums1.size() + nums2.size() >> 1) - m1 - 1;
                if (nums1[m1] <= nums2[m2] && nums2[m2] <= nums1[m1 + 1])
                    return nums2[m2];
                else if (nums2[m2] <= nums1[m1] && nums1[m1] <= nums2[m2 + 1])
                    return nums1[m1];
                else if (nums1[m1] < nums2[m2])
                    l = (l + r >> 1) + 1;
                else
                    r = l + r >> 1;
            }
        else
            for (int l = 0, r = nums1.size() - 1; ; ) {
                int m1 = l + r >> 1,
                    m2 = (nums1.size() + nums2.size() >> 1) - m1 - 2;
                if (nums1[m1] <= nums2[m2] && nums2[m2 + 1] <= nums1[m1 + 1])
                    return (nums2[m2] + nums2[m2 + 1]) / 2.0;
                else if (nums2[m2] <= nums1[m1] && nums1[m1 + 1] <= nums2[m2 + 1])
                    return (nums1[m1] + nums1[m1 + 1]) / 2.0;
                else if (nums1[m1] <= nums2[m2] && nums2[m2] <= nums1[m1 + 1] && nums1[m1 + 1] <= nums2[m2 + 1])
                    return (nums2[m2] + nums1[m1 + 1]) / 2.0;
                else if (nums2[m2] <= nums1[m1] && nums1[m1] <= nums2[m2 + 1] && nums2[m2 + 1] <= nums1[m1 + 1])
                    return (nums1[m1] + nums2[m2 + 1]) / 2.0;
                else if (nums1[m1 + 1] <= nums2[m2])
                    l = (l + r >> 1) + 1;
                else
                    r = l + r >> 1;
            }
    }
};