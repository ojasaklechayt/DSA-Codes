class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        maxSumBSTHelper(root, maxSum);
        return maxSum;
    }

private:
    struct Result {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    Result maxSumBSTHelper(TreeNode* root, int& maxSum) {
        if (root == nullptr)
            return {true, 0, INT_MAX, INT_MIN};

        Result left = maxSumBSTHelper(root->left, maxSum);
        Result right = maxSumBSTHelper(root->right, maxSum);

        if (left.isBST && right.isBST && root->val > left.maxVal &&
            root->val < right.minVal) {
            int sum = left.sum + right.sum + root->val;
            maxSum = std::max(maxSum, sum);
            return {true, sum, std::min(root->val, left.minVal),
                    std::max(root->val, right.maxVal)};
        } else {
            return {false, 0, 0, 0};
        }
    }
};
