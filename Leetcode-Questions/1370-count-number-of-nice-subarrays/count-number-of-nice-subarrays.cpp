class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return check(nums, k) - check(nums, k - 1);
    }

private:
    int check(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, nice = 0;
        int odd = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] % 2 != 0)
                odd++;

            while (odd > k) {
                if (nums[left] % 2 != 0)
                    odd--;
                left++;
            }

            nice += (right - left + 1);
        }
        return nice;
    }
};
