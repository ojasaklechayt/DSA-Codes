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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> complement;
        return inorder(root, k, complement);
    }

private:
    bool inorder(TreeNode* root, int k, unordered_map<int, int>& complement){
        if(root == NULL) return false;

        if(complement.find(root->val) != complement.end()){
            return true;
        }

        int complem = k - (root->val);

        complement[complem] = root->val;

        if(inorder(root->left, k, complement)) return true;

        return inorder(root->right, k, complement);
    }
};