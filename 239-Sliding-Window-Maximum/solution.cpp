class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> peek;
        for (int i = 0; i < nums.size(); i++) {
            if (!i || nums[i - 1] < nums[i]) {
                while (!peek.empty() && nums[peek.back()] <= nums[i])
                    peek.pop_back();
                peek.push_back(i);
            }
            while (!peek.empty() && k <= i - peek.front())
                peek.pop_front();
            if (k - 1 <= i)
                if (peek.empty())
                    result.push_back(nums[i - k + 1]);
                else
                    result.push_back(max(nums[i - k + 1], nums[peek.front()]));
        }
        return result;
    }
};