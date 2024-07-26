class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize the adjacency matrix with a large number (INT_MAX) representing infinity
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX));

        // Set the distance from a node to itself to 0
        for (int i = 0; i < n; ++i) {
            adj[i][i] = 0;
        }

        // Populate the adjacency matrix with the given edges
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u][v] = w;
            adj[v][u] = w;
        }

        // Floyd-Warshall algorithm to find the shortest paths between all pairs of nodes
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX) {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }

        // Find the city with the smallest number of reachable cities within the distance threshold
        int cityWithSmallestNumOfNeighbors = -1;
        int smallestNumOfNeighbors = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int numOfNeighbors = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && adj[i][j] <= distanceThreshold) {
                    ++numOfNeighbors;
                }
            }
            if (numOfNeighbors <= smallestNumOfNeighbors) {
                cityWithSmallestNumOfNeighbors = i;
                smallestNumOfNeighbors = numOfNeighbors;
            }
        }

        return cityWithSmallestNumOfNeighbors;
    }
};
