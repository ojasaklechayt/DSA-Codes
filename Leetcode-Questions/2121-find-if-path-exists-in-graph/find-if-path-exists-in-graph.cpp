// class Solution {
// public:
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         unordered_map<int, vector<int>> graph;
//         for(const auto& edge: edges){
//             int u = edge[0];
//             int v = edge[1];
//             graph[u].push_back(v);
//             graph[v].push_back(u);
//         }

//         unordered_set<int> visited;
//         return dfs(graph, source, destination, visited);
//     }

// private:
//     bool dfs(unordered_map<int, vector<int>> graph, int source, int destination, unordered_set<int>& visited){
//         if(source == destination) return true;
//         visited.insert(source);

//         for(int nodes : graph[source]){
//             if(visited.find(nodes) == visited.end()){
//                 if(dfs(graph, nodes, destination, visited)){
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for(const auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        unordered_set<int> visited;
        queue<int> q;
        q.push(source);
        visited.insert(source);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == destination){
                return true;
            }

            for(int neighbour : graph[node]){
                if(visited.find(neighbour) == visited.end()){
                    visited.insert(neighbour);
                    q.push(neighbour);
                }
            }
        }

        return false;
    }
};