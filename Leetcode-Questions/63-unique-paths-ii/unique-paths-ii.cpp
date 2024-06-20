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

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1) {
            return 0;
        }

        memo = vector<vector<int>>(n, vector<int>(m, -1));

        return dfs(0, 0, obstacleGrid);
    }

private:
    vector<vector<int>> memo;

    int dfs(int i, int j, vector<vector<int>>& obstacleGrid){
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if (i >= n || j >= m || obstacleGrid[i][j] == 1) {
            return 0;
        }

        if(i == n-1 && j == m-1){
            return 1;
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int left = dfs(i+1, j,obstacleGrid);
        int right = dfs(i, j+1,obstacleGrid);
        
        memo[i][j] = left + right;

        return memo[i][j];
    }
};