class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != (m * n)) {
            return {};
        }

        vector<vector<int>> arr(m, vector<int>(n));

        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                arr[j][k] = original[j * n + k];
            }
        }
        return arr;
    }
};