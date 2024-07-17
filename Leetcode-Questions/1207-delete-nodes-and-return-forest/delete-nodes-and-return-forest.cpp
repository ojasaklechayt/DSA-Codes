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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());

        root = rec(root, toDeleteSet, forest);
        
        if(root){
            forest.push_back(root);
        }

        return forest;
    }

private:
    TreeNode* rec(TreeNode* node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& forest){
        if(!node){
            return nullptr;
        }

        node->left = rec(node->left, toDeleteSet, forest);
        node->right = rec(node->right, toDeleteSet, forest);

        if(toDeleteSet.find(node->val)!=toDeleteSet.end()){
            if(node->left){
                forest.push_back(node->left);
            } 

            if(node->right){
                forest.push_back(node->right);
            }

            delete node;
            return nullptr;
        }

        return node;
    }
};