// class Solution {
// public:
//     int minInsertions(string s) {
//         int n = s.size(), count = 0;
//         unordered_map<char,int> freq;

//         for(char c: s){
//             freq[c]++;
//         }

//         for(auto& it: freq){
//             if(it.second%2 != 0){
//                 count++;
//             }
//         }

//         return max(0,count-1);
//     }
// };

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= n; len++) { 
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return (n-dp[0][n - 1]);
    }
};