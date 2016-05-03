class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() && closest != target; i++)
            for (int j = i + 1, k = nums.size() - 1; j < k && closest != target; j++) {
                int sum = nums[i] + nums[j];
                while (j < k - 1 && target < sum + nums[k - 1])
                    k--;
                if (abs(sum + nums[k] - target) < abs(closest - target))
                    closest = sum + nums[k];
                if (j < k - 1 && abs(sum + nums[k - 1] - target) < abs(closest - target))
                    closest = sum + nums[k - 1];
            }
        return closest;
    }
};