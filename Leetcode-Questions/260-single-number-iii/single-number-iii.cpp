class Solution {
public:
    // This method finds all numbers that appear exactly once in the given
    // array.
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>
            onenumbers; // Vector to store numbers that appear exactly once
        unordered_map<int, int>
            count; // Hash map to count occurrences of each number

        // Iterate through each number in the input array
        for (auto c : nums) {
            count[c]++; // Increment the count for the current number
        }

        // Iterate through the hash map to find numbers with a count of 1
        for (auto x : count) {
            if (x.second ==
                1) { // Check if the current number appears exactly once
                onenumbers.push_back(x.first); // Add it to the result vector
            }
        }

        return onenumbers; // Return the vector containing numbers that appear
                           // exactly once
    }
};
