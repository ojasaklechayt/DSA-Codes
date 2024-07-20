class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<int> currRowSum(n, 0), curColSum(m, 0);

        int i=0, j=0, k;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++){
                k = min(rowSum[i]-currRowSum[i], colSum[j]-curColSum[j]);
                currRowSum[i]+=k;
                curColSum[j]+=k;
                grid[i][j] = k;
            }
        }

        return grid;
    }
};