/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // Function to find the maximum amount of money that can be robbed from the
    // tree
    int rob(TreeNode* root) {
        // Call the helper function to calculate the maximum values
        auto result = chori(root);
        // Return the maximum of the two values obtained from the root node
        return max(result.first, result.second);
    }

private:
    // Helper function to recursively compute the maximum values when the
    // current node is robbed or not robbed
    pair<int, int> chori(TreeNode* root) {
        // Base case: If the current node is nullptr, return a pair representing
        // no money robbed
        if (root == nullptr) {
            return {0, 0};
        }

        // Recursively calculate the maximum values for the left and right
        // subtrees
        auto left = chori(root->left);
        auto right = chori(root->right);

        // Calculate the maximum value when the current node is robbed
        int robnow = root->val + left.second + right.second;
        // Calculate the maximum value when the current node is not robbed
        int robletter =
            max(left.first, left.second) + max(right.first, right.second);

        // Return a pair representing the maximum values when the current node
        // is robbed and when it's not robbed
        return {robnow, robletter};
    }
};
