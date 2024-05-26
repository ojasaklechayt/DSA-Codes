// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         int start = 0;
//         int end = s.length();
//         vector<vector<int>> dp(end, vector<int>(end, -1));
//         return checkpalindrome(s, start, end-1, dp);
//     }

// private:
//     int checkpalindrome(const string& s, int start, int end,
//                         vector<vector<int>>& dp) {
//         if (start > end) {
//             return 0;
//         }

//         if (start == end) {
//             return 1;
//         }

//         if (dp[start][end] != -1) {
//             return dp[start][end];
//         }

//         if (s[start] == s[end]) {
//             dp[start][end] = 2 + checkpalindrome(s, start + 1, end - 1, dp);
//         } else {
//             dp[start][end] = max(checkpalindrome(s, start, end - 1, dp),
//                                  checkpalindrome(s, start + 1, end, dp));
//         }

//         return dp[start][end];
//     }
// };

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length(); // Get the length of the string
        vector<vector<int>> dp(
            n, vector<int>(n, 0)); // Initialize a 2D vector 'dp' of size n x n
                                   // with all values set to 0

        // Base case: A single character is a palindrome of length 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1; // Every single character is a palindrome of length 1
        }

        // Build the DP table in a bottom-up manner
        // 'len' represents the current length of the substring being considered
        for (int len = 2; len <= n; ++len) {
            // Iterate over all possible starting indices of substrings of
            // length 'len'
            for (int i = 0; i <= n - len; ++i) {
                int j =
                    i + len -
                    1; // Calculate the ending index of the current substring
                if (s[i] == s[j]) {
                    // If the characters at the start and end of the substring
                    // are the same
                    dp[i][j] =
                        dp[i + 1][j - 1] +
                        2; // Include these two characters and add 2 to the
                           // length of the longest palindromic subsequence of
                           // the substring 's[i + 1 ... j - 1]'
                } else {
                    // If the characters at the start and end of the substring
                    // are different
                    dp[i][j] = max(
                        dp[i][j - 1],
                        dp[i + 1]
                          [j]); // Take the maximum length by either excluding
                                // the start character or the end character
                }
            }
        }

        // The value at dp[0][n - 1] gives the length of the longest palindromic
        // subsequence of the entire string 's'
        return dp[0][n - 1];
    }
};
