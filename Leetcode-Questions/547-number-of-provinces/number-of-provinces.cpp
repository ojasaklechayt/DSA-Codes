class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(n,0);
        int count = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                count++;
                dfs(i,adj,vis);
            }
        }

        return count;
    }

private:
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        } 
    }
};