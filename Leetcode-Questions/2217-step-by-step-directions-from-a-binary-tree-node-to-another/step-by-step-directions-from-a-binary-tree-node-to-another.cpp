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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string st;
        string roottostart;
        string roottoend;

        TreeNode* temp = root;
        findpath(temp, roottostart, startValue);
        findpath(temp, roottoend, destValue);

        reverse(roottostart.begin(), roottostart.end());
        reverse(roottoend.begin(), roottoend.end());

        int i = 0, commonLength = min(roottostart.size(), roottoend.size());
        while(i<commonLength && roottostart[i] == roottoend[i]){
            ++i;
        }
        
        string result(roottostart.size() - i, 'U');
        result+=roottoend.substr(i);

        return result;
    }

private:
    bool findpath( TreeNode* root, string &str, int value){
        if(!root) return false;
        if(root->val == value) return true;

        if(root->left && findpath(root->left, str, value)){
            str.push_back('L');
            return true;
        }

        if(root->right && findpath(root->right, str, value)){
            str.push_back('R');
            return true;
        }

        return false;
    }
};