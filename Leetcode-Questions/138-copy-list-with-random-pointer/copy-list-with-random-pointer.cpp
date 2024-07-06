/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> visited;
        return rec(head, visited);
    }

    Node* rec(Node* root, unordered_map<Node*, Node*>& check){
        if(!root) return nullptr;

        if(check.find(root) != check.end()){
            return check[root];
        }

        Node* newNode = new Node(root->val);
        check[root] = newNode;

        newNode->next = rec(root->next, check);
        newNode->random = rec(root->random, check);

        return newNode;
    }
};