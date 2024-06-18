// class Solution {
// public:
//     int numEnclaves(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int count = 0;

//         for(int j = 0; j < m; j++){
//             if(grid[0][j] == 1){
//                 dfs(0, j, grid);
//             }

//             if(grid[n-1][j] == 1){
//                 dfs(n-1, j, grid);
//             }
//         }

//         for(int i = 0; i < n; i++){
//             if(grid[i][0] == 1){
//                 dfs(i, 0, grid);
//             }

//             if(grid[i][m-1] == 1){
//                 dfs(i, m-1, grid);
//             }
//         }

//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(grid[i][j] == 1){
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }

// private:
//     void dfs(int i, int j, vector<vector<int>>& grid){
//         int n = grid.size();
//         int m = grid[0].size();

//         if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!=1) return;

//         grid[i][j] = 2;

//         dfs(i+1,j,grid); 
//         dfs(i-1,j,grid); 
//         dfs(i,j+1,grid); 
//         dfs(i,j-1,grid);   
//     }
// };



class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> check;
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1){
                        check.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0, 1, 0, -1};

        while(!check.empty()){
            int row = check.front().first;
            int col = check.front().second;
            check.pop();
            
            for(int i=0; i<4; i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]==1){
                    check.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    count++;
                }
            }
        }

        return count;
    }
};