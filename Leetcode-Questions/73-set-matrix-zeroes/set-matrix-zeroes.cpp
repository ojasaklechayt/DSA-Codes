class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Get the number of rows (n) and columns (m) in the matrix
        int n = matrix.size();
        int m = matrix[0].size();

        // Initialize flags to check if the first row and first column contain any zeros
        bool firstrow = false;
        bool firstcol = false;
        
        // Check the first row for any zeros
        for(int j = 0; j < m; ++j) {
            if(matrix[0][j] == 0) {
                firstrow = true; // Set flag to true if zero is found
                break; // Exit loop early since we only need to know if there's at least one zero
            }
        }

        // Check the first column for any zeros
        for(int i = 0; i < n; ++i) {
            if(matrix[i][0] == 0) {
                firstcol = true; // Set flag to true if zero is found
                break; // Exit loop early since we only need to know if there's at least one zero
            }
        }

        // Use the first row and first column to mark rows and columns that need to be zeroed
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j < m; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0; // Mark corresponding position in the first column
                    matrix[0][j] = 0; // Mark corresponding position in the first row
                }
            }
        }

        // Zero out marked rows
        for(int i = 1; i < n; ++i){
            if(matrix[i][0] == 0){ // If the row is marked
                for(int j = 0; j < m; ++j){
                    matrix[i][j] = 0; // Set the entire row to zero
                }
            }
        }

        // Zero out marked columns
        for(int j = 1; j < m; ++j){
            if(matrix[0][j] == 0){ // If the column is marked
                for(int i = 0; i < n; ++i){
                    matrix[i][j] = 0; // Set the entire column to zero
                }
            }
        }

        // Zero out the first row if needed
        if(firstrow){
            for(int i = 0; i < m; ++i){
                matrix[0][i] = 0;
            }
        }

        // Zero out the first column if needed
        if(firstcol){
            for(int i = 0; i < n; ++i){
                matrix[i][0] = 0;
            }
        }
    } 
};
