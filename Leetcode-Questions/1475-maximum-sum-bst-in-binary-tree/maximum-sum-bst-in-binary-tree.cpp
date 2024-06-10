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
class info{
 public:
    int maxi;
    int mini;
    bool isbst;
    int sum;
 };
    info solve(TreeNode* root , int &ans){
           if( root ==NULL){
                 return {INT_MIN , INT_MAX   , 1 , 0}; }
           if( root->left ==NULL && root->right ==NULL){
                ans = max(ans , root->val);
                 return {root->val , root->val , true , root->val};
            }

           info leftans = solve(root->left  , ans);
           info rightans = solve( root->right , ans);

             info currentnode;
             currentnode.maxi = max(root->val , rightans.maxi);
             currentnode.mini  = min(root->val  , leftans.mini);
             currentnode.sum = root->val + rightans.sum + leftans.sum;

             if( leftans.isbst && rightans.isbst && ( root->val > leftans.maxi &&              root->val<rightans.mini)){
                   currentnode.isbst = true;}
             else{
                   currentnode.isbst = false;
             }
             if(currentnode.isbst){
                   ans = max(ans, currentnode.sum);
             }
             return currentnode;
    }
public:
    int maxSumBST(TreeNode* root) {
               int ans = 0;
           solve( root , ans );
          return ans;
    }
};