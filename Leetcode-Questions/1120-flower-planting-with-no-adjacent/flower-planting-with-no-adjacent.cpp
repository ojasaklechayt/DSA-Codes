class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        vector<int> gardens(n,0);
        vector<int> vis(n+1, 0);

        for(auto path: paths){
            adj[path[0]-1].push_back(path[1]-1);
            adj[path[1]-1].push_back(path[0]-1);
        }

        for(int i=0; i<n; ++i){
            if(!vis[i]){
                gardens[i] = 1;
                dfs(adj, vis, gardens, i);
            }
        }

        return gardens;
    }

private:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& gardens, int i){
        vis[i] = 1;

        for(int j: adj[i]){
            if(!vis[j]){
                for(int gard = 1; gard<=4; ++gard){
                    bool canUse = true;
                    for(int neighbor: adj[j]){
                        if(gardens[neighbor] == gard){
                            canUse = false;
                            break;
                        }
                    }

                    if(canUse){
                        gardens[j] = gard;
                        break;
                    }
                }
                dfs(adj, vis, gardens, j);
            }
        }
    }
};