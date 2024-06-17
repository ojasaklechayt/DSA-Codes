class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i<m; ++i){
            if(board[i][0] == 'O') solvehelper(i,0,board);
            if(board[i][n-1] == 'O') solvehelper(i,n-1,board);
        }

        for(int i = 0; i<n; ++i){
            if(board[0][i] == 'O') solvehelper(0,i,board);
            if(board[m-1][i] == 'O') solvehelper(m-1,i,board);
        }

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void solvehelper(int i, int j, vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        if(i<0 || i>= m || j<0 || j>=n || board[i][j]!='O') return;

        board[i][j] = '#';

        solvehelper(i+1, j, board);
        solvehelper(i-1, j, board);
        solvehelper(i, j+1, board);
        solvehelper(i, j-1, board);
    }
};