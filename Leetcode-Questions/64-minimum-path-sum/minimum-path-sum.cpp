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
        int n = grid.size(); // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid

        // Initialize the bottom row: 
        // We start from the second last column and move towards the first column
        // We add the value of the cell to the right to the current cell
        // This represents the minimum path sum from each cell to the bottom-right cell
        for (int j = m - 2; j >= 0; j--) {
            grid[n - 1][j] += grid[n - 1][j + 1];
        }

        // Initialize the rightmost column:
        // We start from the second last row and move towards the first row
        // We add the value of the cell below to the current cell
        // This represents the minimum path sum from each cell to the bottom-right cell
        for (int i = n - 2; i >= 0; i--) {
            grid[i][m - 1] += grid[i + 1][m - 1];
        }

        // Build up the grid:
        // We start from the second last row and move towards the first row
        // Within each row, we start from the second last column and move towards the first column
        // For each cell, we add the minimum of the value of the cell to its right and the cell below it
        // This represents the minimum path sum from each cell to the bottom-right cell
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                grid[i][j] += min(grid[i][j + 1], grid[i + 1][j]);
            }
        }

        // Return the minimum path sum from the top-left cell to the bottom-right cell
        return grid[0][0];
    }
};