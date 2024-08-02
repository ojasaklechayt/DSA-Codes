// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size(), length = 0;

//         for(int i=0; i<n; i++){
//             unordered_set<char> hs;
//             for(int j=i; j<n; j++){
//                 if(hs.find(s[j]) != hs.end()){
//                     break;
//                 }
//                 hs.insert(s[j]);
//                 length = max(length, j - i + 1);
//             }
//         }

//         return length;
//     }
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), length = 0, right = 0, left = 0;

        string temp = "";
        while(right<n){
            if(temp.find(s[right])!=string::npos){
                temp.erase(0,1);
                left++;
            } else{
                temp+=s[right];
                right++;
            }
            length = max(length, right-left);
        }

        return length;
    }
};