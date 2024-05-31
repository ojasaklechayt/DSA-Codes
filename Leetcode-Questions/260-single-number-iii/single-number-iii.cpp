// class Solution {
// public:
//     // This method finds all numbers that appear exactly once in the given
//     // array.
//     vector<int> singleNumber(vector<int>& nums) {
//         vector<int>
//             onenumbers; // Vector to store numbers that appear exactly once
//         unordered_map<int, int>
//             count; // Hash map to count occurrences of each number

//         // Iterate through each number in the input array
//         for (auto c : nums) {
//             count[c]++; // Increment the count for the current number
//         }

//         // Iterate through the hash map to find numbers with a count of 1
//         for (auto x : count) {
//             if (x.second ==
//                 1) { // Check if the current number appears exactly once
//                 onenumbers.push_back(x.first); // Add it to the result vector
//             }
//         }

//         return onenumbers; // Return the vector containing numbers that
//         appear
//                            // exactly once
//     }
// };

class Solution {
public:
    // This method finds the two numbers that appear exactly once in the given
    // array, where every other number appears exactly twice.
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int totalxor =
            0; // Initialize a variable to hold the XOR of all elements

        // XOR all elements in the input array
        for (auto c : nums) {
            totalxor ^= c; // XOR each element with totalxor
        }

        // Find the rightmost set bit in the totalxor (this differentiates the
        // two unique numbers)
        unsigned int set_bit = totalxor & -totalxor;

        // Initialize two variables to hold the two unique numbers
        int a = 0, b = 0;

        // Separate the numbers into two groups based on the set bit and XOR
        // within each group
        for (int c : nums) {
            if (c & set_bit) {
                a ^= c; // XOR all numbers where the set bit is 1
            } else {
                b ^= c; // XOR all numbers where the set bit is 0
            }
        }

        // Return the two unique numbers
        return {a, b};
    }
};
