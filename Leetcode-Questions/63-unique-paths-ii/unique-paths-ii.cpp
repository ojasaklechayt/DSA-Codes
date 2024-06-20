// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();

//         if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) {
//             return 0;
//         }

//         return dfs(0, 0, obstacleGrid);
//     }

// private:
//     int dfs(int i, int j, vector<vector<int>>& obstacleGrid){
//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();

//         if (i >= n || j >= m || obstacleGrid[i][j] == 1) {
//             return 0;
//         }

//         if(i == n-1 && j == m-1){
//             return 1;
//         }

//         int left = dfs(i+1, j,obstacleGrid);
//         int right = dfs(i, j+1,obstacleGrid);

//         return left + right;
//     }
// };

// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();

//         if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) {
//             return 0;
//         }

//         memo = vector<vector<int>>(n, vector<int>(m, -1));

//         return dfs(0, 0, obstacleGrid);
//     }

// private:
//     vector<vector<int>> memo;

//     int dfs(int i, int j, vector<vector<int>>& obstacleGrid){
//         int n = obstacleGrid.size();
//         int m = obstacleGrid[0].size();

//         if (i >= n || j >= m || obstacleGrid[i][j] == 1) {
//             return 0;
//         }

//         if(i == n-1 && j == m-1){
//             return 1;
//         }
        
//         if (memo[i][j] != -1) {
//             return memo[i][j];
//         }

//         int left = dfs(i+1, j,obstacleGrid);
//         int right = dfs(i, j+1,obstacleGrid);
        
//         memo[i][j] = left + right;

//         return memo[i][j];
//     }
// };

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        // If the starting point or the ending point is an obstacle, return 0 paths.
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) {
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // Base case: There's one way to be at the starting point.
        dp[0][0] = 1;

        // Fill the first row
        for (int j = 1; j < m; ++j) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = dp[0][j-1];
            }
        }

        // Fill the first column
        for (int i = 1; i < n; ++i) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = dp[i-1][0];
            }
        }

        // Fill the rest of the dp table
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[n-1][m-1];
    }
};
