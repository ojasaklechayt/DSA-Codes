class Solution {
public:
    int minDistance(string word1, string word2) {
        // Get the lengths of both words
        int i = word1.length();
        int j = word2.length();
        
        // Initialize a DP table with dimensions (i+1) x (j+1) and fill it with -1
        // This table will be used to store results of subproblems
        vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
        
        // Call the recursive function to compute the minimum distance
        return totalcount(word1, word2, i, j, dp);
    }

private:
    int totalcount(const string& word1, const string& word2, int i, int j,
                   vector<vector<int>>& dp) {
        // Base case: if word1 is exhausted, return the length of the remaining word2
        if (i == 0) {
            return j;
        }

        // Base case: if word2 is exhausted, return the length of the remaining word1
        if (j == 0) {
            return i;
        }

        // If the result for this subproblem is already computed, return it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // If the last characters of both words are the same, no operation is needed for this character
        // Move to the next pair of characters
        if (word1[i - 1] == word2[j - 1]) {
            dp[i][j] = totalcount(word1, word2, i - 1, j - 1, dp);
        } else {
            // If the last characters are different, consider all three operations:
            // 1. Deleting a character from word1 (move i back)
            // 2. Inserting a character into word1 (move j back)
            // 3. Replacing a character in word1 (move both i and j back)
            dp[i][j] = 1 + min(totalcount(word1, word2, i - 1, j, dp),       // Delete
                               min(totalcount(word1, word2, i - 1, j - 1, dp), // Replace
                                   totalcount(word1, word2, i, j - 1, dp)));    // Insert
        }

        // Return the computed result for this subproblem
        return dp[i][j];
    }
};
