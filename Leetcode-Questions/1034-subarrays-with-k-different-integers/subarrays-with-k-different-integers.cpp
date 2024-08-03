class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return check(nums, k) - check(nums, k - 1);
    }

private:
    int check(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, right = 0, sum = 0;
        unordered_map<int, int> freq;

        while (right < n) {
            freq[nums[right]]++;

            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }

            sum += (right - left + 1);
            right++;
        }

        return sum;
    }
};