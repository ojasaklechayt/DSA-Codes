// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> memo(n, -1);
//         return helper(nums, 0, memo);
//     }

// private:
//     int helper(vector<int>& nums, int i, vector<int>& memo){
//         int n = nums.size();
//         if(i>=(n-1)) return 0;
//         if(memo[i] != -1) return memo[i];

//         int min_jumps = INT_MAX;
//         int fardest = min(n-1, i+nums[i]);

//         for(int j=i+1; j<=fardest; ++j){

//             int jumps = helper(nums, j, memo);

//             if(jumps!=INT_MAX){
//                 min_jumps = min(min_jumps, jumps + 1);
//             }
//         }

//         memo[i] = min_jumps;
//         return memo[i];
//     }
// };

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);

        dp[0] = 0;

        for(int i=1; i<n; ++i){
            for(int j=0; j<=i; ++j){
                if(j+nums[j] >= i){
                    if(dp[j]!=INT_MAX){
                        dp[i] = min(dp[i], dp[j]+1);
                    }
                }
            }
        }

        return dp[n-1];
    }
};