class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), sum = 0, maxlen = 0;
        unordered_map<int,int> prefix;
        prefix[0] = -1;

        for(int i=0; i<n; i++){
            if(nums[i] == 0) sum-=1;
            else sum+=1;

            if(prefix.find(sum)!=prefix.end()){
                maxlen = max(maxlen, i-prefix[sum]);
            } else {
                prefix[sum] = i;
            }
        }

        return maxlen;
    }
};