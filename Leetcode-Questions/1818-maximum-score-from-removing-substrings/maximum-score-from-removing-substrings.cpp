class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int points = 0;
        stack<char> st1, st2;

        char first, second;
        int firstpoint, secondpoint;

        if(x > y){
            firstpoint = x;
            secondpoint = y;
            first = 'a';
            second = 'b'; 
        } else {
            firstpoint = y;
            secondpoint = x;
            first = 'b';
            second = 'a'; 
        }

        for (char c : s) {
            if(!st1.empty() && st1.top() == first && c == second){
                st1.pop();
                points += firstpoint;
            } else {
                st1.push(c);
            }
        }

        while(!st1.empty()){
            char top = st1.top();
            st1.pop();
            if(!st2.empty() && st2.top() == first && top == second){
                st2.pop();
                points += secondpoint;
            } else {
                st2.push(top);
            }
        }

        return points;
    }
};