class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();    // Number of rows in the matrix
        int m = matrix[0].size(); // Number of columns in the matrix
        int count =
            0; // Variable to store the total count of square submatrices

        // Create a 2D vector 'dp' with the same dimensions as 'matrix',
        // initialized to -1
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // Initialize the first row of 'dp' with the values from the first row
        // of 'matrix'
        for (int i = 0; i < m; i++) {
            dp[0][i] = matrix[0][i];
        }

        // Initialize the first column of 'dp' with the values from the first
        // column of 'matrix'
        for (int i = 0; i < n; i++) {
            dp[i][0] = matrix[i][0];
        }

        // Iterate through the matrix starting from the second row and the
        // second column
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                // If the current element in 'matrix' is 1, calculate the size
                // of the largest square submatrix ending at this element
                if (matrix[i][j] == 1) {
                    // The value of 'dp[i][j]' is 1 plus the minimum of the
                    // values from the cell directly above, the cell directly to
                    // the left, and the cell diagonally above-left
                    dp[i][j] = 1 + min(dp[i - 1][j],
                                       min(dp[i - 1][j - 1], dp[i][j - 1]));
                } else {
                    // If the current element in 'matrix' is 0, there can't be
                    // any square submatrix ending at this element
                    dp[i][j] = 0;
                }
            }
        }

        // Sum up all the values in the 'dp' matrix to get the total count of
        // square submatrices
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                count += dp[i][j];
            }
        }

        // Return the total count of square submatrices
        return count;
    }
};
