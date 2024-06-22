// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         int count = 0;
        
//         for(int i = 0; i < n; i++) {
//             int odd = 0;
//             for(int j = i; j < n; j++) {
//                 if(nums[j] % 2 != 0) {
//                     ++odd;
//                 }
                
//                 if(odd == k) {
//                     ++count;
//                 } else if (odd > k) {
//                     break;
//                 }
//             }
//         }
        
//         return count;
//     }
// };

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> oddIndices;
        oddIndices.push_back(-1); // Dummy index to handle edge cases
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 != 0) {
                oddIndices.push_back(i);
            }
        }
        oddIndices.push_back(n); // Dummy index to handle edge cases

        int count = 0;
        int m = oddIndices.size();
        
        if (m <= k + 1) {
            return 0; // If there are fewer than k+1 odd numbers, return 0
        }

        for (int i = 1; i + k < m; ++i) {
            int leftCount = oddIndices[i] - oddIndices[i - 1];
            int rightCount = oddIndices[i + k] - oddIndices[i + k - 1];
            count += leftCount * rightCount;
        }

        return count;
    }
};
