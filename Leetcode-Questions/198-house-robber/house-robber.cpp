class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return robFrom(0, nums, memo);
    }

private:
    int robFrom(int i, vector<int>& nums, vector<int>& memo) {
        if (i >= nums.size()) {
            return 0;
        }
        
        if (memo[i] != -1) {
            return memo[i];
        }
        
        int robCurrent = nums[i] + robFrom(i + 2, nums, memo);
        int skipCurrent = robFrom(i + 1, nums, memo);
        
        memo[i] = max(robCurrent, skipCurrent);
        return memo[i];
    }
};
