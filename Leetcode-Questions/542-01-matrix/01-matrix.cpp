class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<int>> dist(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                    dist[i][j] = 0;
                }
            }
        }

        vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();

            for(auto dir: directions){
                int nx = x + dir.first;
                int ny = y + dir.second;

                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    dist[nx][ny] = d+1;
                    q.push({{nx,ny}, d+1});
                }
            }
        }

        return dist;
    }
};