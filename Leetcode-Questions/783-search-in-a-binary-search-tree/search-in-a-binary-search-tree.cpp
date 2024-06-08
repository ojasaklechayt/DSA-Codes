/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /**
     * Function to search for a value in a binary search tree.
     * @param root Root of the binary search tree.
     * @param val Value to search for in the binary search tree.
     * @return TreeNode pointer to the node containing the value if found, otherwise NULL.
     */
    TreeNode* searchBST(TreeNode* root, int val) {
        // If the root is NULL or the value is found at the root, return the root.
        if(root == NULL){
            return root;
        }

        if(root->val == val){
            return root;
        }

        // Recursively search the left subtree for the value.
        TreeNode* leftRoot = searchBST(root->left, val);
        if(leftRoot != NULL){
            return leftRoot; // If found in the left subtree, return the node.
        }

        // If not found in the left subtree, recursively search the right subtree.
        return searchBST(root->right, val);
    }
};
