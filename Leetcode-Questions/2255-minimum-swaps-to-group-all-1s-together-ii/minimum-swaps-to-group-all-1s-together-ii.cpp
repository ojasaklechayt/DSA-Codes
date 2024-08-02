class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), countone = 0;

        for(int i: nums){
            if(i==1) countone++;
        }

        int zeros = 0, maxZeros = INT_MAX;

        for(int i=0; i<countone; i++){
            if(nums[i] == 0) zeros++;
        }

        maxZeros = zeros;

        for(int i = countone; i < (n+countone); i++){
            if(nums[i%n] == 0) zeros++;
            if(nums[(i-countone)%n] == 0) zeros--;
            maxZeros = min(maxZeros, zeros);
        }

        return maxZeros;
    }
};