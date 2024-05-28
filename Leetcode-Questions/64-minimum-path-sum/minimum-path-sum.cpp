// class Solution {
// public:
//     // Public function to calculate the minimum path sum from top-left to
//     // bottom-right of the grid.
//     int minPathSum(vector<vector<int>>& grid) {
//         // Initialize the memoization table with -1 to indicate uncomputed
//         cells vector<vector<int>> memo(grid.size(),
//         vector<int>(grid[0].size(), -1));
//         // Start the recursive path finding from the top-left corner (0, 0)
//         return path(grid, memo, 0, 0);
//     }

// private:
//     // Recursive helper function to calculate the minimum path sum from cell
//     (i, j)
//     // to the bottom-right corner.
//     int path(vector<vector<int>>& grid, vector<vector<int>>& memo, int i, int
//     j) {
//         int n = grid.size();    // Number of rows in the grid
//         int m = grid[0].size(); // Number of columns in the grid

//         // Base case: If the current position is out of bounds, return a
//         large
//         // number (infinity). This represents an invalid path.
//         if (i >= n || j >= m) {
//             return INT_MAX;
//         }

//         // Base case: If the current position is the bottom-right cell,
//         return
//         // its value. This is the destination cell, and we can't move
//         further. if (i == n - 1 && j == m - 1) {
//             return grid[i][j];
//         }

//         // Check if the current cell's value is already computed and stored
//         in memo if (memo[i][j] != -1) {
//             return memo[i][j];
//         }

//         // Recursive case: Calculate the minimum path sum by moving right and
//         down.
//         // Move right to the cell (i, j + 1)
//         int right = path(grid, memo, i, j + 1);
//         // Move down to the cell (i + 1, j)
//         int down = path(grid, memo, i + 1, j);

//         // Add the current cell's value to the minimum of the sums obtained
//         from
//         // the right and down paths.
//         memo[i][j] = grid[i][j] + min(right, down);

//         // Return the calculated sum for the current cell (i, j)
//         return memo[i][j];
//     }
// };

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: Initialize the bottom-right cell
        dp[n - 1][m - 1] = grid[n - 1][m - 1];

        // Initialize the bottom row
        for (int j = m - 2; j >= 0; j--) {
            dp[n - 1][j] = grid[n - 1][j] + dp[n - 1][j + 1];
        }

        // Initialize the rightmost column
        for (int i = n - 2; i >= 0; i--) {
            dp[i][m - 1] = grid[i][m - 1] + dp[i + 1][m - 1];
        }

        // Build up the dp table
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                dp[i][j] = grid[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
            }
        }

        return dp[0][0];
    }
};