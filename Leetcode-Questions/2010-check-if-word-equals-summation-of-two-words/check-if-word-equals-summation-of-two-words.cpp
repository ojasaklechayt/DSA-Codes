class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int first = 0;
        int second = 0;
        int target = 0;

        for(char c: firstWord){
            first = first*10 + (c - 'a');
        }

        for(char c : secondWord){
            second = second*10 + (c - 'a');
        }

        for(char c : targetWord){
            target = target*10 + (c - 'a');
        }

        int total = first + second; 

        return (total == target);
    }
};