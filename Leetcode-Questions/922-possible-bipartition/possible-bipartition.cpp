class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> vis(n + 1, -1);  // Initialize visitation state for all nodes
        vector<vector<int>> adj(n + 1);

        // Build the adjacency list
        for (auto& d : dislikes) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        // Check each component of the graph
        for (int i = 1; i <= n; i++) {
            if (vis[i] == -1) {
                if (!check(i, adj, vis)) return false;
            }
        }

        return true;
    }

private:
    bool check(int i, vector<vector<int>>& adj, vector<int>& vis) {
        queue<int> q;
        q.push(i);
        vis[i] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto& it : adj[node]) {
                if (vis[it] == -1) {
                    vis[it] = !vis[node];
                    q.push(it);
                } else if (vis[it] == vis[node]) {
                    return false;
                }
            }
        }

        return true;
    }
};
