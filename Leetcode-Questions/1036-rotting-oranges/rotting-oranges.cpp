class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> qt;
        int freshCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    qt.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0)
            return 0;

        int mins = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!qt.empty()) {
            int size = qt.size();
            bool rottenThisMinutes = false;

            for (int i = 0; i < size; i++) {
                auto [x, y] = qt.front();
                qt.pop();

                for(auto [ax, bx]: directions){
                    int nx = x + ax;
                    int ny = y + bx;

                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        qt.push({nx, ny});
                        freshCount--;
                        rottenThisMinutes = true;
                    }
                }
            }

            if(rottenThisMinutes) mins++;
        }

        return freshCount == 0 ? mins : -1;
    }
};
