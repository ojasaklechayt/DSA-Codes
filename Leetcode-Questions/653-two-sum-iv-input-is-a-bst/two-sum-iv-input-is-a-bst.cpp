class Solution {
public:
    // Main function to find if there exist two elements in the BST that add up
    // to the given target.
    bool findTarget(TreeNode* root, int k) {
        // Initialize a map to store complements.
        unordered_map<int, int> complement;
        // Call helper function inorder() to traverse the BST and find the
        // target sum.
        return inorder(root, k, complement);
    }

private:
    // Helper function to perform inorder traversal and find the target sum.
    bool inorder(TreeNode* root, int k, unordered_map<int, int>& complement) {
        // If the current node is NULL, return false.
        if (root == NULL)
            return false;

        // If the complement of the current node's value is found in the map,
        // return true.
        if (complement.find(root->val) != complement.end()) {
            return true;
        }

        // Calculate the complement of the current node's value.
        int complem = k - (root->val);

        // Insert the complement into the map with the current node's value as
        // the corresponding value.
        complement[complem] = root->val;

        // Recursively check the left subtree. If a pair is found, return true.
        if (inorder(root->left, k, complement))
            return true;

        // Recursively check the right subtree. If a pair is found, return true.
        return inorder(root->right, k, complement);
    }
};