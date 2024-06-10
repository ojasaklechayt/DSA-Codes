class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // Create a copy of the heights vector called correct
        vector<int> correct;

        // Copy the contents of the original heights vector to the correct
        // vector
        correct = heights;

        // Sort the correct vector in non-decreasing order
        sort(correct.begin(), correct.end());

        // Initialize a counter to keep track of the number of mismatched
        // heights
        int count = 0;

        // Iterate through each element in the heights vector
        for (int i = 0; i < heights.size(); i++) {
            // Compare the original height with the sorted height at the same
            // index
            if (heights[i] != correct[i]) {
                // Increment the count if there is a mismatch
                count++;
            }
        }

        // Return the total number of mismatched heights
        return count;
    }
};
