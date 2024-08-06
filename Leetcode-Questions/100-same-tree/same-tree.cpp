// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         queue<TreeNode*> pt, qt;
//         pt.push(p);
//         qt.push(q);

//         while (!pt.empty() && !qt.empty()) {
//             TreeNode* topp = pt.front();
//             pt.pop();

//             TreeNode* topq = qt.front();
//             qt.pop();

//             if (!topp && !topq) {
//                 continue; // Both nodes are null, continue to next
//             }

//             if (!topp || !topq || topp->val != topq->val) {
//                 return false; // One node is null or values differ
//             }

//             // Push children into the queues
//             pt.push(topp->left);
//             qt.push(topq->left);
//             pt.push(topp->right);
//             qt.push(topq->right);
//         }

//         // Both queues should be empty if trees are identical
//         return pt.empty() && qt.empty();
//     }
// };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }

public:
    bool dfs(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;

        if (!p || !q || p->val != q->val) {
            return false; 
        }

        return dfs(p->left, q->left) && dfs(p->right, q->right);
    }
};