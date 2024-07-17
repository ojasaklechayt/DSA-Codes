// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//  * right(right) {}
//  * };
//  */
// class Solution {
// public:
//     vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
//         vector<TreeNode*> forest;
//         unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());

//         root = rec(root, toDeleteSet, forest);
        
//         if(root){
//             forest.push_back(root);
//         }

//         return forest;
//     }

// private:
//     TreeNode* rec(TreeNode* node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& forest){
//         if(!node){
//             return nullptr;
//         }

//         node->left = rec(node->left, toDeleteSet, forest);
//         node->right = rec(node->right, toDeleteSet, forest);

//         if(toDeleteSet.find(node->val)!=toDeleteSet.end()){
//             if(node->left){
//                 forest.push_back(node->left);
//             } 

//             if(node->right){
//                 forest.push_back(node->right);
//             }

//             delete node;
//             return nullptr;
//         }

//         return node;
//     }
// };


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
        if(!root) return forest;

        queue<TreeNode*> q;
        q.push(root);

        if(toDeleteSet.find(root->val) == toDeleteSet.end()){
            forest.push_back(root);
        }

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                q.push(node->left);
                if(toDeleteSet.find(node->left->val) != toDeleteSet.end()){
                    node->left = nullptr;
                }
            }

            if(node->right){
                q.push(node->right);
                if(toDeleteSet.find(node->right->val) != toDeleteSet.end()){
                    node->right = nullptr;
                }
            }

            if(toDeleteSet.find(node->val) != toDeleteSet.end()){
                if(node->left){
                    forest.push_back(node->left);
                } 
                if(node->right){
                    forest.push_back(node->right);
                }
            }
        }
        
        return forest;
    }
};