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
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        
        TreeNode* dummy = new TreeNode(0);
        TreeNode* prev = dummy;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* current = st.top();
            st.pop();

            prev->right = current;
            prev->left = nullptr;
            prev = current;

            if(current->right) st.push(current->right);
            if(current->left) st.push(current->left);
        }
    }
};
