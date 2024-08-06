class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

private:
    int dfs(TreeNode* node, int& maxSum) {
        if (node == nullptr) return 0;

        int leftGain = max(dfs(node->left, maxSum), 0);
        int rightGain = max(dfs(node->right, maxSum), 0);

        int currentPathSum = node->val + leftGain + rightGain;

        maxSum = max(maxSum, currentPathSum);

        return node->val + max(leftGain, rightGain);
    }
};