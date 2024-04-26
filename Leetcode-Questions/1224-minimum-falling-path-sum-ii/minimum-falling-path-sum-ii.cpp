class Solution {
public:
    vector<vector<int>> dp;
    int minFallingPathSum(vector<vector<int>>& grid) {
        int sum = INT_MAX;
        dp = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        for(int j = 0; j < grid[0].size(); j++) {
            sum = min(sum, takesum(0, j, grid));
        }
        return sum;
    }

private:
    int takesum(int i, int j, vector<vector<int>>& grid) {
        if(i == grid.size() - 1) return grid[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];

        int cur = INT_MAX;
        for(int x=0; x<grid[0].size(); x++){
            if(x!=j){
                cur = min(cur, takesum(i+1, x, grid));
            }
        }

        dp[i][j] = cur + grid[i][j];
        return dp[i][j];
    }
};
