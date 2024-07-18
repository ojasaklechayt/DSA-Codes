// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int countPairs(TreeNode* root, int distance) {
//         int goodn = 0;
//         vector<TreeNode*> leafNodes;
//         dfs(root, leafNodes);
//         for(int i = 0; i<leafNodes.size(); i++){
//             for(int j = i+1; j<leafNodes.size(); j++){
//                 int gap = dist(leafNodes[i], leafNodes[j], root);
//                 if(gap<=distance){
//                     goodn++;
//                 }
//             }
//         }

//         return goodn;
//     }

// private:
//     void dfs(TreeNode* root, vector<TreeNode*>& leafNodes){
//         if(root == NULL) return;
        
//         if(root->left==NULL && root->right==NULL){
//             leafNodes.push_back(root);
//             return;
//         }

//         dfs(root->left, leafNodes);
//         dfs(root->right, leafNodes);
//     }

//     int dist(TreeNode* nodeone, TreeNode* nodetwo, TreeNode* root){
//         if(root == NULL || nodeone == NULL || nodetwo == NULL){
//             return -1;
//         }

//         TreeNode* lcs = findLCA(root, nodeone, nodetwo);

//         int dist1 = findDistance(lcs, nodeone, 0);
//         int dist2 = findDistance(lcs, nodetwo, 0);

//         return dist1+dist2;
//     }

//     TreeNode* findLCA(TreeNode* root, TreeNode* nodeone, TreeNode* nodetwo){
//         if(root == NULL || root == nodeone || root == nodetwo){
//             return root;
//         }

//         TreeNode* left = findLCA(root->left, nodeone, nodetwo);
//         TreeNode* right = findLCA(root->right, nodeone, nodetwo);

//         if(left!=NULL && right!=NULL){
//             return root;
//         }

//         return left!=NULL ? left : right;
//     }

//     int findDistance(TreeNode* root, TreeNode* target, int dist){
//         if(root == NULL){
//             return -1;
//         }

//         if(root == target){
//             return dist;
//         }

//         int left = findDistance(root->left, target, dist+1);
//         if(left!=-1){
//             return left;
//         }

//         return findDistance(root->right, target, dist+1);
//     }
// };

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int goodn = 0;
        helper(root, distance, goodn);
        return goodn;
    }

private:
    vector<int> helper(TreeNode* node, int distance, int& goodn){
        if(!node) return {};
        if(!node->left && !node->right) return {1};

        vector<int> leftDistance = helper(node->left, distance, goodn);
        vector<int> rightDistance = helper(node->right, distance, goodn);

        for(int ld: leftDistance){
            for(int rd: rightDistance){
                if(ld+rd <= distance){
                    goodn++;
                }
            }
        }

        vector<int> result;
        for(int ld: leftDistance){
            if(ld+1 <= distance) result.push_back(ld+1);
        }

        for(int rd: rightDistance){
            if(rd+1 <= distance) result.push_back(rd+1);
        }

        return result;
    }
};