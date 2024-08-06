class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> order;
        if (!root) return order;

        queue<TreeNode*> qt;
        qt.push(root);

        while (!qt.empty()) {
            int levelSize = qt.size();
            vector<int> temp;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* top = qt.front();
                qt.pop();
                temp.push_back(top->val);

                if (top->left) {
                    qt.push(top->left);
                }

                if (top->right) {
                    qt.push(top->right);
                }
            }
            order.push_back(temp);
        }

        return order;
    }
};