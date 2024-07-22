// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int area = 0;
//         for(int i=0;i<heights.size(); i++){
//             int height = INT_MAX;
//             for(int j=i; j<heights.size(); j++){
//                 height = min(height, heights[j]);
//                 area = max(area, height*(j-i+1));
//             }
//         }

//         return area;
//     }
// };

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         stack<int> st;
//         vector<int> prevsmaller(n), nextsmaller(n);

//         for (int i = 0; i < n; i++) {
//             while (!st.empty() && heights[st.top()] >= heights[i]) {
//                 st.pop();
//             }

//             if (st.empty()) {
//                 prevsmaller[i] = 0;
//             } else {
//                 prevsmaller[i] = st.top() + 1;
//                 st.push(i);
//             }
//         }

//         while (!st.empty()) {
//             st.pop();
//         }

//         for(int i = n-1; i>=0; i--){
//             while(!st.empty() && heights[st.top()] >= heights[i]){
//                 st.top();
//             }

//             if(st.empty()){
//                 nextsmaller[i] = n - 1;
//             } else {
//                 nextsmaller[i] = st.top() - 1;
//             }

//             st.push(i);
//         }

//         int maxA = 0;
//         for(int i=0; i<n; i++){
//             maxA = max(maxA, heights[i]*(nextsmaller[i]-prevsmaller[i]+1));
//         }
//         return maxA;
//     }
// };

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<int> stack;
        stack.push(-1);
        int max_area = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (stack.top() != -1 && heights[i] <= heights[stack.top()]) {
                int height = heights[stack.top()];
                stack.pop();
                int width = i - stack.top() - 1;
                max_area = std::max(max_area, height * width);
            }
            stack.push(i);
        }

        while (stack.top() != -1) {
            int height = heights[stack.top()];
            stack.pop();
            int width = heights.size() - stack.top() - 1;
            max_area = std::max(max_area, height * width);
        }

        return max_area;        
    }
};