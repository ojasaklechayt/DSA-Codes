class Solution {
public:
    string removeDigit(string number, char digit) {
        string str = "";
        int n = number.size();
        
        for (int i = 0; i < n; i++) {
            if(number[i] == digit){
                str = max(str, number.substr(0,i) + number.substr(i+1,n));
            }
        }

        return str;
    }
};