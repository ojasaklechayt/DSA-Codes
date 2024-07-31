class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int maxWidth = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long left = q.front().second, right = q.back().second;

            maxWidth = max(maxWidth, int(right - left + 1));

            for (int i = 0; i < size; ++i) {
                auto [node, pos] = q.front();
                q.pop();

                if (node->left) {
                    q.push({node->left, 2 * pos});
                }
                if (node->right) {
                    q.push({node->right, 2 * pos + 1});
                }
            }
        }

        return maxWidth;
    }
};