class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);

        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }

        vector<int> cities(n);
        for (int i = 0; i < n; ++i) {
            cities[i] = i;
        }

        sort(cities.begin(), cities.end(), [&](int a, int b) {
            return degree[a] > degree[b];
        });
        
        vector<int> importance(n);
        for (int i = 0; i < n; ++i) {
            importance[cities[i]] = n - i;
        }

        long long totalImportance = 0;
        for (const auto& road : roads) {
            totalImportance += importance[road[0]] + importance[road[1]];
        }

        return totalImportance;
    }
};