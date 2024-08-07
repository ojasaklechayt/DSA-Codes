class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> freq;

        for (int i = 0; i < inorder.size(); i++) {
            freq[inorder[i]] = i;
        }

        int index = postorder.size() - 1;
        return helper(postorder, inorder, 0, inorder.size() - 1, freq, index);
    }

private:
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder, int left, int right, unordered_map<int, int>& map, int& index) {
        if (left > right) {
            return nullptr;
        }

        int curr = postorder[index--];
        TreeNode* node = new TreeNode(curr);

        int inorderIndex = map[curr];
        node->right = helper(postorder, inorder, inorderIndex + 1, right, map, index);
        node->left = helper(postorder, inorder, left, inorderIndex - 1, map, index);

        return node;
    }
};