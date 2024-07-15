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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeTree;
        unordered_set<int> nodetree;

        for(auto& desc: descriptions){
            int parent = desc[0], child = desc[1], isLeft = desc[2];

            if(nodeTree.find(parent) == nodeTree.end()){
                nodeTree[parent] = new TreeNode(parent);
            } 

            if(nodeTree.find(child) == nodeTree.end()){
                nodeTree[child] = new TreeNode(child);
            }

            if(isLeft){
                nodeTree[parent]->left = nodeTree[child];
            } else {
                nodeTree[parent]->right = nodeTree[child];
            }

            nodetree.insert(child);
        }

        TreeNode* root = new TreeNode();
        for(auto& desc: descriptions){
            int parent = desc[0];
            if(nodetree.find(parent) == nodetree.end()){
                root = nodeTree[parent];
            }
        }

        return root;
    }
};