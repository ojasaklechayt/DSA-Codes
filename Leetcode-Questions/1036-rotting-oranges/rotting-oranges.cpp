class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        bool anyChange = false;

        do {
            anyChange = false;
            vector<vector<int>> newGrid = grid;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 2) {
                        if (rot(i + 1, j, grid, newGrid)) anyChange = true;
                        if (rot(i - 1, j, grid, newGrid)) anyChange = true;
                        if (rot(i, j + 1, grid, newGrid)) anyChange = true;
                        if (rot(i, j - 1, grid, newGrid)) anyChange = true;
                    }
                }
            }

            if (anyChange) {
                grid = newGrid;
                count++;
            }
        } while (anyChange);

        // Check if there are any fresh oranges left.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return count;
    }

private:
    bool rot(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& newGrid) {
        int n = grid.size();
        int m = grid[0].size();
        if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1) {
            newGrid[i][j] = 2;
            return true;
        }
        return false;
    }
};
