

using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> dist(n + 1, vector<int>(2, INT_MAX));
        vector<int> freq(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        dist[1][0] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            freq[node]++;

            if(freq[node]==2 && node==n) return currentDist;
            if((currentDist/change)%2) currentDist = change*(currentDist/change+1) + time;
            else currentDist = currentDist + time;

            for (auto& adjNode : adj[node]) {
                if(freq[adjNode] == 2) continue;

                if (currentDist < dist[adjNode][0]) {
                    dist[adjNode][1] = dist[adjNode][0];
                    dist[adjNode][0] = currentDist;
                    pq.push({currentDist, adjNode});
                } else if(currentDist > dist[adjNode][0] && currentDist < dist[adjNode][1]){
                    dist[adjNode][1] = currentDist;
                    pq.push({currentDist, adjNode});
                }
            }
        }

        return 0;
    }
};
