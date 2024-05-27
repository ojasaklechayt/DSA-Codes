// class Solution {
// public:
//     // Main function to solve the circular house robber problem
//     int rob(vector<int>& nums) {
//         // If there's only one house, return the value of that house
//         if (nums.size() == 1) {
//             return nums[0];
//         }
//         // Return the maximum value by solving two scenarios:
//         // 1. Robbing houses from the first to the second last
//         // 2. Robbing houses from the second to the last
//         return max(maxchori(nums, 0, nums.size() - 2), maxchori(nums, 1,
//         nums.size() - 1));
//     }

// private:
//     // Helper function to solve the linear version of the house robber
//     problem
//     // for the specified subarray (from index 'i' to 'end')
//     int maxchori(vector<int>& nums, int i, int end) {
//         // Base case: If the current index 'i' is beyond the end index,
//         return 0 if (i > end) {
//             return 0;
//         }

//         // Base case: If the current index 'i' is the end index, return the
//         value at 'i' if (i == end) {
//             return nums[i];
//         }

//         // Recursive case: Calculate the maximum money if robbing the current
//         house
//         // Rob the current house and move to the house at index 'i + 2'
//         int robCurrent = nums[i] + maxchori(nums, i + 2, end);

//         // Calculate the maximum money if skipping the current house
//         // Skip the current house and move to the house at index 'i + 1'
//         int skipCurrent = maxchori(nums, i + 1, end);

//         // Return the maximum value between robbing and skipping the current
//         house return max(robCurrent, skipCurrent);
//     }
// };

class Solution {
public:
    // Main function to solve the circular house robber problem
    int rob(vector<int>& nums) {
        // Check if the input array is empty
        if (nums.size() == 0) {
            return 0; // If empty, return 0 (no houses to rob)
        }

        // Check if the input array is having one item
        if (nums.size() == 1) {
            return nums[0]; // If only one, return nums[0] (only 1 houses to rob)
        }

        // Initialize memoization arrays for both scenarios
        vector<int> memo1(nums.size(),
                          -1); // For scenario 1 (from 0 to nums.size() - 2)
        vector<int> memo2(nums.size(),
                          -1); // For scenario 2 (from 1 to nums.size() - 1)

        // Return the maximum amount of money that can be robbed from either
        // scenario
        return max(maxchori(nums, 0, nums.size() - 2, memo1),  // Scenario 1
                   maxchori(nums, 1, nums.size() - 1, memo2)); // Scenario 2
    }

private:
    // Recursive helper function to compute the maximum amount of money that can
    // be robbed starting from index 'i' and ending at index 'end' using
    // memoization
    int maxchori(vector<int>& nums, int i, int end, vector<int>& memo) {
        // Base case: If the current index 'i' exceeds the end index, return 0
        // (no more houses to rob)
        if (i > end) {
            return 0;
        }

        // Base case: If the current index 'i' equals the end index, return the
        // value of the house at 'i'
        if (i == end) {
            return nums[i];
        }

        // If the result for the current index 'i' has already been computed,
        // return it from the memoization array
        if (memo[i] != -1) {
            return memo[i];
        }

        // Recursive cases:
        // 1. Calculate the maximum amount of money if robbing the current house
        // ('nums[i]')
        //    and moving to the next available non-adjacent house (two houses
        //    away)
        int robCurrent = nums[i] + maxchori(nums, i + 2, end, memo);

        // 2. Calculate the maximum amount of money if skipping the current
        // house and
        //    moving to the next available house (one house away)
        int skipCurrent = maxchori(nums, i + 1, end, memo);

        // Store the maximum of the two results in the memoization array for
        // future use
        memo[i] = max(robCurrent, skipCurrent);

        // Return the maximum amount of money that can be robbed starting from
        // index 'i' and ending at index 'end'
        return memo[i];
    }
};
