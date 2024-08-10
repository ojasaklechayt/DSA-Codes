class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> map(3 * n, vector<int>(3 * n, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    map[i * 3][j * 3 + 2] = 1;
                    map[i * 3 + 1][j * 3 + 1] = 1;
                    map[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    map[i * 3][j * 3] = 1;
                    map[i * 3 + 1][j * 3 + 1] = 1;
                    map[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < map.size(); ++i) {
            for (int j = 0; j < map[0].size(); ++j) {
                if (map[i][j] == 0) { 
                    count++;
                    dfs(i, j, map);
                }
            }
        }

        return count;
    }

private:
    void dfs(int i, int j, vector<vector<int>>& map) {
        int n = map.size();
        if (i < 0 || j < 0 || i >= n || j >= n || map[i][j] != 0) {
            return;
        }

        map[i][j] = 2;

        dfs(i - 1, j, map);
        dfs(i + 1, j, map);
        dfs(i, j - 1, map);
        dfs(i, j + 1, map);
    }
};
