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
    int maxDepth(TreeNode* root) {
        int height;
        height = dfs(root);
        return height;
    }

private:
    int dfs(TreeNode* root){
        int height = 0;
        if(root == nullptr){
            return 0;
        }
        
        height = max(1 + dfs(root->right), 1 + dfs(root->left));

        return height;
    }
};