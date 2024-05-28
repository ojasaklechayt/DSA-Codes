#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Function to find the difference between two permutations represented by
    // strings s and t
    int findPermutationDifference(string s, string t) {
        int sum = 0; // Initialize the sum to store the difference
        unordered_map<char, int>
            map1; // Map to store character positions in string s
        unordered_map<char, int>
            map2; // Map to store character positions in string t

        // Populate map1 with character positions in string s
        for (int i = 0; i < s.size(); i++) {
            map1[s[i]] = i;
        }

        // Populate map2 with character positions in string t
        for (int i = 0; i < t.size(); i++) {
            map2[t[i]] = i;
        }

        // Iterate through characters and their positions in map1
        for (auto c : map1) {
            // Calculate the absolute difference between the position of the
            // same character in map1 and map2
            sum += abs(c.second - map2[c.first]);
        }

        // Return the total difference
        return sum;
    }
};
