class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = 1;
        string repeated_a = a;

        while(repeated_a.size() < b.size()){
            repeated_a += a;
            count++;
        }

        if (repeated_a.find(b) != string::npos) return count;

        repeated_a += a;
        if (repeated_a.find(b) != string::npos) return count + 1;

        return -1;
    }
};
