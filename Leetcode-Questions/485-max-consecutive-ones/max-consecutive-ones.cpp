class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = INT_MIN;
        
        int cur = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                ++cur;
            } else {
                maxi = max(maxi, cur);
                cur = 0;
            }
        }

        maxi = max(maxi, cur);
        
        return maxi;
    }
};