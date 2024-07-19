// class Solution {
// public:
//     vector<int> luckyNumbers(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         int i = 0, j = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 int xt = INT_MAX, yt = INT_MIN;
//                 for (int k = 0; k < m; k++) {
//                     xt = min(xt, matrix[i][k]);
//                 }

//                 for (int k = 0; k < n; k++) {
//                     yt = max(yt, matrix[k][j]);
//                 }

//                 if (xt == yt) {
//                     return {xt};
//                 }
//             }
//         }

//         return {};
//     }
// };


class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> rows;
        for(int i=0; i<n; i++){
            int xt = INT_MAX;
            for(int j=0; j<m; j++){
                xt = min(xt, matrix[i][j]);
            }
            rows.push_back(xt);
        }

        vector<int> cols;
        for(int i=0; i<m; i++){
            int yt = INT_MIN;
            for(int j=0; j<n; j++){
                yt = max(yt, matrix[j][i]);
            }
            cols.push_back(yt);
        }

        vector<int> luckynumber;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == rows[i] && matrix[i][j] == cols[j]){
                    luckynumber.push_back(matrix[i][j]);
                }
            }
        }

        return luckynumber;
    }
};