// class Solution {
// public:
//     bool isPalindrome(int x) {
//         string num = to_string(x);
//         string rnum = "";

//         for(char c: num){
//             rnum = c + rnum;
//         }

//         return (num == rnum);
//     }
// };


class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        int left = 0;
        int right = num.size() - 1;

        while(left < right){
            if(num[left]!=num[right]){
                return false;
            }
            
            left++;
            right--;
        }

        return true;
    }
};