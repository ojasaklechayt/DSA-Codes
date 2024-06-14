/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

private:
    Node* helperclone(Node* &node, unordered_map<int, Node*> &visited){
        Node* t = new Node(node->val);
        visited[node->val] = t;
        for(Node* nnode: node->neighbors){
            if(visited.find(nnode->val) == visited.end()){
                t->neighbors.push_back(helperclone(nnode, visited));
            } else {
                t->neighbors.push_back(visited[nnode->val]);
            }
        }
        return t;
    }

public:
    unordered_map<int, Node*> visited;
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        if(node->neighbors.empty()) return new Node(node->val);
        return helperclone(node,visited);
    }
};