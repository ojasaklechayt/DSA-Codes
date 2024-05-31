// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         int row = 0;
//         int col = m-1;
//         while(row<n && col>=0){
//             if(matrix[row][col] == target){
//                 return true;
//             } else if (target > matrix[row][col]){
//                 row++;
//             } else {
//                 col--;
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n; i++){
            if(booleancheck(matrix[i] , target)){
                return true;
            }
        }

        return false;
    }

private:
    bool booleancheck(vector<int> row,  int target){
        int start = 0;
        int end = row.size()-1;

        while(start <= end){  
            int mid = start + (end-start)/2;
            if(row[mid] == target){
                return true;
            } else if (row[mid] < target){
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }
};