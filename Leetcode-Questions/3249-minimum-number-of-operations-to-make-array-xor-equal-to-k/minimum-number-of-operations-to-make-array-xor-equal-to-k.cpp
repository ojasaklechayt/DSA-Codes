class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // Initialize a variable to store the XOR result of all elements in 'nums'
        int temp = 0;
        for(auto i: nums){
            temp = temp ^ i; // XOR operation with each element
        }

        // Initialize a counter for the number of operations needed
        int ans = 0;
        for(int i=0; i<32; i++){
            // Check if the i-th bit of 'k' is different from the i-th bit of 'temp'
            if((k & (1 << i)) != (temp & (1 << i))){
                ans++; // Increment the operation count
            }
        }

        return ans; // Return the total number of operations
    }
};


