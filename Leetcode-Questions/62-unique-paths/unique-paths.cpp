class Solution {
public:
    // Function to find the number of unique paths from the top-left cell to the
    // bottom-right cell
    int uniquePaths(int m, int n) {
        int total = 0; // Initialize the total count of unique paths
        // Create a map to keep track of visited cells. Initialize all cells as
        // unvisited (false)
        vector<vector<bool>> map(m, vector<bool>(n, false));
        // Start calculating paths from the top-left cell (0, 0)
        total += calculatepath(map, 0, 0);
        return total; // Return the total number of unique paths
    }

private:

    unordered_map<string,int> memo; // Memoization map to store calculated paths

    // Recursive function to calculate the number of unique paths from a given
    // cell (m, n) to the bottom-right cell
    int calculatepath(vector<vector<bool>>& map, int m, int n) {
        // Get the number of rows and columns in the map
        int i = map.size();
        int j = map[0].size();

        string key = to_string(m) + ',' + to_string(n); // Create a unique key for the current cell
        // Check if the result for the current cell is already memoized
        if(memo.find(key) != memo.end()){
            return memo[key]; // Return the memoized result
        }
        
        // If the current cell is out of bounds, return 0 (no paths)
        if (m >= i || n >= j) {
            return 0;
        }
        // If the current cell is the bottom-right cell, return 1 (one unique
        // path found)
        if (m == i - 1 && n == j - 1) {
            return 1;
        }
        // Mark the current cell as visited
        map[m][n] = true;

        int totalpaths = 0; // Initialize the count of unique paths from the current cell
        // If moving down is within bounds and the cell below is unvisited,
        // explore that path
        if (m + 1 < i && !map[m + 1][n]) {
            totalpaths += calculatepath(map, m + 1, n);
        }
        // If moving right is within bounds and the cell to the right is
        // unvisited, explore that path
        if (n + 1 < j && !map[m][n + 1]) {
            totalpaths += calculatepath(map, m, n + 1);
        }
        // After exploring all paths from the current cell, mark it as unvisited
        // (backtracking)
        map[m][n] = false;

        memo[key] = totalpaths; // Memoize the result for the current cell

        return totalpaths; // Return the total number of unique paths from this
                           // cell
    }
};
