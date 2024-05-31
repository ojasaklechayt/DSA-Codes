class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int k = -1;

        // Finding the largest index k such that nums[k] < nums[k+1]
        for(int i = n-2; i >= 0; i-- ){
            if(nums[i] < nums[i+1]){
                k = i;
                break;
            }
        }

        // If no such index is found, the entire sequence is in descending order,
        // so we reverse it to get the smallest possible permutation.
        if (k == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the smallest number greater than nums[k] to the right of nums[k]
        int minval = n - 1;
        for(int j = n-1; j > k; j-- ){
            if(nums[j] > nums[k]){
                minval = j;
                break;
            }
        }

        // Swap nums[k] and the smallest number greater than nums[k] found earlier
        swap(nums[k], nums[minval]);

        // Reverse the subarray from k+1 to the end to get the next permutation
        reverse(nums.begin() + k + 1, nums.end());
    }
};
