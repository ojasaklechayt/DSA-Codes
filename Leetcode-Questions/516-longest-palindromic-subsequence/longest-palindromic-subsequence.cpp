class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int start = 0;
        int end = s.length();
        vector<vector<int>> dp(end, vector<int>(end, -1));
        return checkpalindrome(s, start, end-1, dp);
    }

private:
    int checkpalindrome(const string& s, int start, int end,
                        vector<vector<int>>& dp) {
        if (start > end) {
            return 0;
        }

        if (start == end) {
            return 1;
        }

        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        if (s[start] == s[end]) {
            dp[start][end] = 2 + checkpalindrome(s, start + 1, end - 1, dp);
        } else {
            dp[start][end] = max(checkpalindrome(s, start, end - 1, dp),
                                 checkpalindrome(s, start + 1, end, dp));
        }

        return dp[start][end];
    }
};