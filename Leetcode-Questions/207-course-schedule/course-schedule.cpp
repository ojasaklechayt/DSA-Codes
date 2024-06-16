class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);

        for(const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        for(int i=0; i<numCourses; i++){
            if(vis[i] == 0){
                if(detact(i, adj, vis)) return false;
            }
        }

        return true;
    }

private:
    bool detact(int src, vector<vector<int>>& adj, vector<int>& vis){
        vis[src] = 1;
        for(int neigh: adj[src]){
            if(vis[neigh] == 0){
                if(detact(neigh, adj, vis)){
                    return true;
                }
            } else if(vis[neigh] == 1){
                return true;
            }
        }

        vis[src] = 2;
        return false;
    }
};