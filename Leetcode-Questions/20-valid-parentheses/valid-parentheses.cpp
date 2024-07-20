class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 1) {
            return false;
        }

        stack<char> st;

        for (char c : s) {
            if (c == '[' || c == '(' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                } else {
                    char top = st.top();
                    st.pop();
                    if ((top != '(' && c == ')') ||
                        (top != '[' && c == ']') ||
                        (top != '{' && c == '}')) {
                            return false;
                    }
                }
            }
        }

        return st.empty();
    }
};