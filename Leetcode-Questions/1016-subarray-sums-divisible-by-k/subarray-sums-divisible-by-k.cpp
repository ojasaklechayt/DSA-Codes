// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;
//         for(int i = 0; i < n; i++){
//             int sum = 0;
//             for(int j = i; j < n; j++){
//                 sum += nums[j];
//                 if(sum % k == 0){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // HashMap to store the frequency of prefix sums modulo k
        unordered_map<int, int> freq;
        // Initialize the frequency of remainder 0 to 1
        // This handles the case where a prefix sum itself is divisible by k
        freq[0] = 1;

        int prefix_sum = 0; // To store the running prefix sum
        int count = 0;      // To count the number of subarrays divisible by k

        // Iterate through each element in the nums array
        for (int c : nums) {
            // Update the running prefix sum
            prefix_sum += c;

            // Calculate the remainder when prefix_sum is divided by k
            // Adding k and then taking modulo k ensures the remainder is
            // non-negative
            int remainder = ((prefix_sum % k) + k) % k;

            // If this remainder has been seen before, it means there are
            // subarrays that end at the current index and have sums divisible
            // by k
            if (freq.find(remainder) != freq.end()) {
                // Increment count by the frequency of this remainder
                count += freq[remainder];
            }

            // Update the frequency of the current remainder in the hashmap
            freq[remainder]++;
        }

        // Return the total count of subarrays whose sums are divisible by k
        return count;
    }
};
