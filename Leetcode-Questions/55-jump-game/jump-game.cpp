class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int approachable = 0;
        for(int i=0; i<n; i++){
            if(i>approachable) return false;
            approachable = max(approachable, i+nums[i]);
            if(approachable >= n-1) return true;
        }
        return false;
    }
};