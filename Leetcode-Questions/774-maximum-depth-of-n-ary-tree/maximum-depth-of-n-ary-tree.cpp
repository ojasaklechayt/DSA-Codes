/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        return dfs(root);
    }

private:
    int dfs(Node* root){
        if(root == nullptr) return 0;

        int max_depth = 0;

        for(Node* child: root->children){
            max_depth = max(max_depth, dfs(child));
        }

        return 1 + max_depth;
    }
};