#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Define a struct to represent each character along with its index in the
    // original string.
    struct node {
        char ch;
        int idx;
    };

    // Define a comparison functor to compare nodes based on their characters
    // and indices.
    struct compare {
        bool operator()(const node& a, const node& b) {
            // If characters are equal, prioritize the node with the lower
            // index.
            if (a.ch == b.ch)
                return a.idx < b.idx;
            // Otherwise, prioritize the character with the higher ASCII value.
            return a.ch > b.ch;
        }
    };

    // Function to clear '*' characters from the string.
    string clearStars(string s) {
        // Priority queue to store nodes (characters along with their indices),
        // ordered by the defined comparison.
        priority_queue<node, vector<node>, compare> queue;

        // Iterate through the string.
        for (int i = 0; i < s.size(); i++) {
            // If the character is '*', pop the top node from the priority queue
            // if it's not empty.
            if (s[i] == '*') {
                if (queue.size() > 0)
                    queue.pop();
            }
            // Otherwise, push the node representing the character along with
            // its index.
            else {
                queue.push({s[i], i});
            }
        }

        // Vector to store sorted nodes extracted from the priority queue.
        vector<node> sortedNodes;
        while (!queue.empty()) {
            // Push the top node into the vector and pop it from the priority
            // queue.
            sortedNodes.push_back(queue.top());
            queue.pop();
        }

        // Sort the sortedNodes vector based on the indices of the nodes.
        sort(sortedNodes.begin(), sortedNodes.end(),
             [](const node& a, const node& b) { return a.idx < b.idx; });

        // Construct the result string from the characters stored in
        // sortedNodes.
        string result;
        for (const auto& n : sortedNodes) {
            result += n.ch;
        }

        // Return the resulting string with '*' characters cleared.
        return result;
    }
};
