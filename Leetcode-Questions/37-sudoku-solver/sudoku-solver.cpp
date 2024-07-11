class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) { 
        sudoku(board, 0); 
    }

private:
    bool sudoku(vector<vector<char>>& board, int row) {
        int n = board.size();   
        int m = board[0].size();

        if (row == n) {
            return true;
        }

        for (int i = row; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.') {
                    for(char k='1'; k<='9'; k++){
                        if(isvalid(i, j, board, k)){
                            board[i][j] = k;
                            if(sudoku(board, i)){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    bool isvalid(int row, int col, vector<vector<char>> board, char k) {
        int n = board.size();

        for (int i = 0; i < n; i++) {
            if (board[i][col] == k) {
                return false;
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[row][i] == k) {
                return false;
            }
        }

        int subgridRowStart = (row / 3) * 3;
        int subgridColStart = (col / 3) * 3;
        for (int i = subgridRowStart; i < subgridRowStart + 3; i++) {
            for (int j = subgridColStart; j < subgridColStart + 3; j++) {
                if (board[i][j] == k) {
                    return false;
                }
            }
        }

        return true;
    }
};