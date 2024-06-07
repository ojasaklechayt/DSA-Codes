class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int total = 1;
        int n = 1;

        if (nums.size() == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            } else if (nums[i - 1] + 1 == nums[i]) {
                n++;
                total = max(total, n);
            } else {
                n = 1;
            }
        }

        return total;
    }
};