class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0, j = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int xt = INT_MAX, yt = INT_MIN;
                for (int k = 0; k < m; k++) {
                    xt = min(xt, matrix[i][k]);
                }

                for (int k = 0; k < n; k++) {
                    yt = max(yt, matrix[k][j]);
                }

                if (xt == yt) {
                    return {xt};
                }
            }
        }

        return {};
    }
};