class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Initialize in-degree and adjacency list
        vector<int> inDegrees(numCourses, 0); // Stores in-degree of each course
        vector<vector<int>> adjList(
            numCourses,
            vector<int>()); // Adjacency list for course relationships

        // Step 2: Build the in-degree and adjacency list based on prerequisites
        for (auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prerequisiteFor = prerequisite[1];
            inDegrees[course]++; // Increment in-degree of the course
            adjList[prerequisiteFor].push_back(
                course); // Add course to adjacency list of prerequisites
        }

        // Step 3: Initialize a queue to perform topological sort
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegrees[i] == 0)
                q.push(i); // Push all courses with zero in-degree to the queue
        }

        // Step 4: Perform topological sorting using Kahn's Algorithm
        vector<int> order; // Resultant order of courses

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node); // Add course to the order

            // Decrease the in-degree of neighboring courses and push to queue
            // if in-degree becomes zero
            for (int neighbor : adjList[node]) {
                if (--inDegrees[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 5: Check if topological sort is possible (i.e., all courses are
        // included)
        if (order.size() != numCourses) {
            return {}; // Return empty vector if not all courses are included
                       // (indicating a cycle)
        }

        return order; // Return the topological order of courses
    }
};
