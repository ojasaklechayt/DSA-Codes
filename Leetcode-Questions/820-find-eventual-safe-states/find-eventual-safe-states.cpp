class Solution {
private:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis
    , vector<int>& check){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it,adj, vis, pathVis,check) == true){
                    check[node] = 0;
                    return true;
                }
            }

            else if(pathVis[it]){
                check[node] = 0;
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), 0);
        vector<int> pathVis(graph.size(), 0);
        vector<int> check(graph.size(), 0);
        vector<int> safeNodes;
        for(int i=0; i<graph.size(); i++){
            if(!vis[i]){
                dfs(i,graph, vis,pathVis, check);
            }
        }

        for(int i=0; i<graph.size(); i++){
            if(check[i] == 1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};