class Solution {
public:
    int minOperations(vector<string>& logs) {
        int operations = 0;

        for(int i=0; i<logs.size(); i++){
            if(logs[i] == "../"){
                if(operations == 0){
                    continue;
                } else {
                    operations--;
                }
            } else if(logs[i] == "./"){
                continue;
            } else {
                operations++;
            }
        }

        return operations;
    }
};