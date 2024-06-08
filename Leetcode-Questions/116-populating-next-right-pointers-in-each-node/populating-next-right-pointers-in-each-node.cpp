// #include <queue>
// using namespace std;

// // Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node* next;

//     Node() : val(0), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val, Node* _left, Node* _right, Node* _next)
//         : val(_val), left(_left), right(_right), next(_next) {}
// };

class Solution {
public:
    Node* connect(Node* root) {
        // Check if the root is NULL
        if (root == NULL) {
            return NULL; // If root is NULL, return NULL
        }

        queue<Node*> q; // Create a queue to perform level order traversal
        q.push(root);   // Push the root node into the queue

        while (!q.empty()) { // Continue until the queue becomes empty
            int s =
                q.size(); // Get the current size of the queue, which represents
                          // the number of nodes at the current level
            Node* prev = NULL; // Initialize a pointer to track the previous
                               // node in the current level

            for (int i = 0; i < s;
                 ++i) { // Traverse through all nodes at the current level
                Node* current = q.front(); // Get the front node of the queue
                q.pop(); // Remove the front node from the queue

                if (prev !=
                    NULL) { // If there is a previous node in the current level
                    prev->next = current; // Set the next pointer of the
                                          // previous node to the current node
                }
                prev = current; // Update the previous node pointer to the
                                // current node

                if (current->left !=
                    NULL) { // If the current node has a left child
                    q.push(current->left); // Push the left child into the queue
                }

                if (current->right !=
                    NULL) { // If the current node has a right child
                    q.push(
                        current->right); // Push the right child into the queue
                }
            }
        }
        return root; // Return the modified root node with next pointers
                     // connected
    }
};
