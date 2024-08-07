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
    void flatten(TreeNode* root) {
        if(root == nullptr) return;

        TreeNode* dummy = new TreeNode(0);
        TreeNode* prev = dummy;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* top = st.top();
            st.pop();

            prev->right = top;
            prev->left = nullptr;
            prev = top;

            if(top->right) st.push(top->right);
            if(top->left) st.push(top->left);
        }

        root = prev;
    }
};