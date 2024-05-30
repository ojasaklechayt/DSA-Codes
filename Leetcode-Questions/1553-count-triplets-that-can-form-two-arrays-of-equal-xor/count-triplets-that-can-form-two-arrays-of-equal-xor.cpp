// class Solution {
// public:
//     int countTriplets(std::vector<int>& arr) {
//         int n = arr.size(); // Get the size of the array
//         int total = 0;      // Initialize the counter for triplets

//         // Iterate through each starting index i
//         for (int i = 0; i < n; i++) {
//             int xora = 0; // Initialize xora to store the XOR from i to j-1

//             // Iterate through each possible ending index j
//             for (int j = i + 1; j < n; j++) {
//                 xora ^= arr[j - 1]; // Compute XOR from i to j-1 by updating
//                 xora int xorb = 0;   // Initialize xorb to store the XOR from
//                 j to k

//                 // Iterate through each possible index k starting from j
//                 for (int k = j; k < n; k++) {
//                     xorb ^= arr[k]; // Compute XOR from j to k by updating
//                     xorb

//                     // If XOR of arr[i...j-1] is equal to XOR of arr[j...k],
//                     // increment total
//                     if (xora == xorb) {
//                         total++; // We found a valid triplet (i, j, k)
//                     }
//                 }
//             }
//         }

//         return total; // Return the total number of triplets found
//     }
// };

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(); // Get the size of the input array
        int total = 0;      // Initialize the total count of triplets to zero
        vector<int> startxor(n + 1,
                             0); // Initialize a vector to store cumulative XOR
                                 // values, with an extra space for convenience

        // Compute cumulative XOR up to each index
        for (int i = 0; i < n; i++) {
            startxor[i + 1] =
                startxor[i] ^ arr[i]; // XOR of previous cumulative XOR value
                                      // and the current array element
        }

        // Iterate through the array to find valid triplets
        for (int k = 0; k < n; k++) {         // Iterate from 0 to n-1
            for (int j = k + 1; j < n; j++) { // Iterate j from k+1 to n-1
                if (startxor[k] ==
                    startxor[j + 1]) { // Check if XOR from 0 to k-1 equals XOR
                                       // from 0 to j
                    total += (j - k);  // Add the number of triplets found
                }
            }
        }

        return total; // Return the total number of valid triplets
    }
};
