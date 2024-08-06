class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> qt;
        qt.push(root);

        bool flag = true;

        while (!qt.empty()) {
            int size = qt.size();
            vector<int> temp(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = qt.front();
                qt.pop();

                int index = (flag) ? i : (size - 1 - i);
                temp[index] = node->val;

                if (node->left) {
                    qt.push(node->left);
                }

                if (node->right) {
                    qt.push(node->right);
                }
            }
            result.push_back(temp);
            flag = !flag;
        }

        return result;
    }
};
