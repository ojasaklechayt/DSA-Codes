class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;

        for(string c: details){
            if(stoi(c.substr(11,2)) > 60){
                count++;
            }
        }

        return count;
    }
};