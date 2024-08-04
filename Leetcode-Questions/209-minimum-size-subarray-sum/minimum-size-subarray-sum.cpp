class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), left = 0, sum = 0, size = INT_MAX;

        for(int right = 0; right<n; right++){
            sum+=nums[right];
            while(sum>=target){
                size = min(size, right-left+1);
                sum-=nums[left++];
            }
        }

        return size == INT_MAX ? 0 : size;
    }
};