class Solution {
public:
    typedef pair<long long, int> pii;

    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        long long totalCost = 0;
        vector<vector<pair<int, int>>> adj(26);
        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int w = cost[i];
            adj[u].push_back({v, w});
        }  

        vector<vector<long long>> minConv(26, vector<long long>(26, LLONG_MAX));
        for (int i = 0; i < 26; ++i) {
            minConv[i] = calculateCost(i, adj);
        }

        for (int i = 0; i < source.size(); ++i) {
            if (source[i] != target[i]) {
                int u = source[i] - 'a';
                int v = target[i] - 'a';
                long long cost = minConv[u][v];
                if (cost == LLONG_MAX) {
                    return -1; 
                }
                totalCost += cost;
            }
        }

        return totalCost;
    }

private:
    vector<long long> calculateCost(int source, vector<vector<pair<int, int>>>& adj) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<long long> dist(26, LLONG_MAX);
        pq.push({0, source});
        dist[source] = 0;

        while (!pq.empty()) {
            long long currentCost = pq.top().first;
            int currentChar = pq.top().second;
            pq.pop();

            if (currentCost > dist[currentChar]) continue;

            for (auto& [targetChar, conversionCost] : adj[currentChar]) {
                if (currentCost + conversionCost < dist[targetChar]) {
                    dist[targetChar] = currentCost + conversionCost;
                    pq.push({dist[targetChar], targetChar});
                }
            }
        }

        return dist;
    }
};
