class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int length = 0, left = 0, right = 0, n = nums.size(), countzeros = 0;

        while(right < n){
            if(nums[right] == 0) countzeros++;
    
            while(countzeros > k){
                if(nums[left] == 0) countzeros--;
                left++;
            }
            length = max(length, right-left+1);
            right++;
        }

        return length;
    }
};