class Solution {
    vector<int> origin;
public:
    Solution(vector<int> nums) : origin(nums) {
        srand(time(nullptr));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> nums(origin);
        for (int i = 0; i < nums.size(); i++)
            swap(nums[i], nums[rand() % (nums.size() - i) + i]);
        return nums;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */