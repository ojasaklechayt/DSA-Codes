public class LongestCommonSubsequenceDP {

    // Method to find the length of LCS using dynamic programming
    public static int lcs(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();

        // Create a 2D array to store intermediate results
        int[][] dp = new int[m + 1][n + 1];

        // Fill the dp array iteratively
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                // Base case: if either of the strings is empty, LCS is 0
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                // If the characters at current positions match, include them in LCS
                else if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                // If the characters don't match, take the maximum of skipping one character from either string
                else
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        // Return the length of LCS from the bottom-right corner of the dp array
        return dp[m][n];
    }

    // Main method to test the implementation
    public static void main(String[] args) {
        String s1 = "AGGTAB";
        String s2 = "GXTXAYB";
        System.out.println("Length of LCS: " + lcs(s1, s2));
    }
}
