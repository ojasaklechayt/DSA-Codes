// class Solution {
// public:
//     int maxSatisfaction(vector<int>& satisfaction) {
//         // Sort the satisfaction array in ascending order.
//         sort(satisfaction.begin(), satisfaction.end());

//         // Call the helper function to compute the maximum satisfaction.
//         return maximumFull(satisfaction, 0, 1);
//     }

// private:
//     int maximumFull(vector<int>& satisfaction, int index, int time) {
//         int n = satisfaction.size();

//         // Base case: If we've processed all items, return 0.
//         if (index >= n) {
//             return 0;
//         }

//         // Recursive case:
//         // 1. Skip the current item and move to the next one.
//         int skip = maximumFull(satisfaction, index + 1, time);

//         // 2. Include the current item:
//         //    - Multiply its satisfaction value by the time it takes to
//         //      consume it.
//         //    - Recurse with the next item and increased time.
//         int count = (satisfaction[index] * time) +
//                     maximumFull(satisfaction, index + 1, time + 1);

//         // Return the maximum of the two options.
//         return max(skip, count);
//     }
// };

// class Solution {
// public:
//     int maxSatisfaction(vector<int>& satisfaction) {
//         // Sort the satisfaction array in ascending order.
//         sort(satisfaction.begin(), satisfaction.end());

//         // Create a 2D DP array to store intermediate results.
//         // dp[i][j] represents the maximum satisfaction considering
//         // the first i items and consuming them in j time units.
//         vector<vector<int>> dp(satisfaction.size() + 1,
//                                vector<int>(satisfaction.size() + 2, 0));

//         // Call the helper function to compute the maximum satisfaction.
//         return maximumFull(dp, satisfaction, 0, 1);
//     }

// private:
//     int maximumFull(vector<vector<int>>& dp, vector<int>& satisfaction,
//                     int index, int time) {
//         int n = satisfaction.size();

//         // Base case: If we've processed all items, return 0.
//         if (index >= n) {
//             return 0;
//         }

//         // If the result for the current state is already computed, return
//         it. if (dp[index][time] != 0) {
//             return dp[index][time];
//         }

//         // Recursive case:
//         // 1. Skip the current item and move to the next one.
//         int skip = maximumFull(dp, satisfaction, index + 1, time);

//         // 2. Include the current item:
//         //    - Multiply its satisfaction value by the time it takes to
//         consume it.
//         //    - Recurse with the next item and increased time.
//         int count = (satisfaction[index] * time) +
//                     maximumFull(dp, satisfaction, index + 1, time + 1);

//         // Store the maximum of the two options in the DP table.
//         dp[index][time] = max(skip, count);

//         // Return the computed result.
//         return dp[index][time];
//     }
// };

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        // Sort the satisfaction array
        sort(satisfaction.begin(), satisfaction.end());

        // Create a DP table with all values initialized to 0
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        // Fill the DP table
        for (int i = n - 1; i >= 0; --i) {
            for (int t = 1; t <= n; ++t) {
                // Option 1: Do not include the i-th dish
                int notTake = dp[i + 1][t];

                // Option 2: Include the i-th dish
                int take = satisfaction[i] * t + dp[i + 1][t + 1];

                // Take the maximum of both options
                dp[i][t] = max(notTake, take);
            }
        }

        // The result is the maximum satisfaction we can get starting with the
        // first dish and t=1
        return dp[0][1];
    }
};