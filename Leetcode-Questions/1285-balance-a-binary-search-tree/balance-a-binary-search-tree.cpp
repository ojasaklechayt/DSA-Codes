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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        nodehelper(root, nodes);
        return sortedarr(nodes, 0, nodes.size()-1);
    }

private:
    void nodehelper(TreeNode* root, vector<int>& node){
        if(root == nullptr) return;
        nodehelper(root->left, node);
        node.push_back(root->val);
        nodehelper(root->right, node);
    }

    TreeNode* sortedarr(vector<int>& nodes, int start, int end){
        if(start>end) return nullptr;
        int mid = start + (end-start)/2;
        TreeNode* node = new TreeNode(nodes[mid]);
        node->left = sortedarr(nodes, start, mid-1);
        node->right = sortedarr(nodes, mid+1, end);
        return node;
    }
};