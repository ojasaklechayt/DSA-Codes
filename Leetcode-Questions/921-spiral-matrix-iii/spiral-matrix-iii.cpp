class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> path;
        int i = rStart, j = cStart;
        int totalCells = rows * cols;

        int direction[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int steps = 1, d = 0;

        path.push_back({i, j});

        while (path.size() < totalCells) {
            for (int k = 0; k < 2; k++) {
                for (int s = 0; s < steps; s++) {
                    i += direction[d][0];
                    j += direction[d][1];

                    if (i >= 0 && i < rows && j >= 0 && j < cols) {
                        path.push_back({i, j});
                    }
                }
                d = (d + 1) % 4;
            }
            steps++;
        }

        return path;
    }
};
