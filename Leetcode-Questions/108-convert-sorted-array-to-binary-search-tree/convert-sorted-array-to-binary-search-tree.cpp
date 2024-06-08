class Solution {
public:
    /**
     * Converts a sorted array into a height-balanced binary search tree (BST).
     * @param nums A vector of integers sorted in ascending order.
     * @return The root node of the height-balanced BST.
     */
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Call the helper function to construct the BST from the sorted array
        return maketree(nums, 0, nums.size() - 1);
    }

private:
    /**
     * A recursive helper function to construct a BST from a sorted array.
     * @param nums A vector of integers sorted in ascending order.
     * @param left The starting index of the subarray to be converted.
     * @param right The ending index of the subarray to be converted.
     * @return The root node of the BST constructed from the subarray.
     */
    TreeNode* maketree(vector<int>& nums, int left, int right) {
        // Base case: If the left index exceeds the right index, return nullptr
        if (left > right) {
            return nullptr;
        }

        // Calculate the middle index of the current subarray
        int mid = left + (right - left) / 2;

        // Create a new tree node with the middle element of the subarray
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively construct the left subtree using the left half of the
        // current subarray
        root->left = maketree(nums, left, mid - 1);

        // Recursively construct the right subtree using the right half of the
        // current subarray
        root->right = maketree(nums, mid + 1, right);

        // Return the root node of the BST
        return root;
    }
};