class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // Initialize the maximum length of the substring
        int length = 0;
        // Get the size of the strings s and t
        int n = s.size();
        // Initialize the current total cost of the substring
        int temp = 0;
        // Initialize the start pointer of the sliding window
        int start = 0;

        // Iterate over the characters of the strings using the end pointer
        for (int end = 0; end < n; end++) {
            // Add the cost of converting the current character from s to t to
            // the total cost
            temp += abs(s[end] - t[end]);

            // If the total cost exceeds maxCost, adjust the window from the
            // start
            if (temp > maxCost) {
                // Subtract the cost of the character at the start pointer from
                // the total cost
                temp -= abs(s[start] - t[start]);
                // Move the start pointer to the right to shrink the window
                start++;
            }

            // Calculate the length of the current valid substring and update
            // the maximum length
            length = max(length, end - start + 1);
        }

        // Return the maximum length of the substring where the total cost does
        // not exceed maxCost
        return length;
    }
};
