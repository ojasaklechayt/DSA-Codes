class Solution {
public:
    string reverseParentheses(string s) {
        string result;
        stack<int> st;

        for(char c: s){
            if(c == '('){
                st.push(result.length());
            } else if(c == ')'){
                int len = st.top();
                st.pop();
                reverse(result.begin() + len, result.end());
            } else {
                result+=c;
            }
        }

        return result;
    }
};