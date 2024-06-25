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
    TreeNode* bstToGst(TreeNode* root) {
        int Csum = 0;
        helper(root, Csum);
        return root;
    }   

private:
    void helper(TreeNode* root, int& Csum){
        if(root == nullptr) return;
        helper(root->right, Csum);
        Csum += root->val;
        root->val = Csum;
        helper(root->left, Csum);

    }
};