class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int MinDiff = INT_MAX;

        TreeNode* prev = nullptr;

        inorder(root, prev, MinDiff);

        return MinDiff;
    }

private:
    void inorder(TreeNode* root, TreeNode*& prev, int& MinDiff){
        if(!root) return;

        inorder(root->left, prev, MinDiff);

        if(prev){
            MinDiff = min(MinDiff, abs(root->val - prev->val));
        }

        prev = root;

        inorder(root->right, prev, MinDiff);
    }
};