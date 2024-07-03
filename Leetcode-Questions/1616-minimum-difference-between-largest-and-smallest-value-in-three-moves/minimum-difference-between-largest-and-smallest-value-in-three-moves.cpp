class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;

        sort(nums.begin(), nums.end());
        int diff = INT_MAX;

        int i = 0;
        while (i <= 3) {
            diff = min(diff, nums[n - 1 - i] - nums[3 - i]);
            i++;
        }

        return diff;
    }
};
