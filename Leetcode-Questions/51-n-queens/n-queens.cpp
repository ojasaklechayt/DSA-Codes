class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        nqueens(board, 0, result);
        return result;
    }

private:
    void nqueens(vector<string>& board, int row, vector<vector<string>>& result){
        int n = board.size();

        if(row == n){
            result.push_back(board);
            return;
        }

        for(int col=0; col<n; col++){
            if(isvalid(board, row, col)){
                board[row][col] = 'Q';
                nqueens(board, row+1, result);
                board[row][col] = '.';
            }
        }
    }

    bool isvalid(vector<string> board, int row, int col){
        int n = board.size();

        for(int i=0; i<row; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }

        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }
};