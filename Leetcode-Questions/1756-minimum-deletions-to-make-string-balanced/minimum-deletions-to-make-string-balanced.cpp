// class Solution {
// public:
//     int minimumDeletions(string s) {
//         int n = s.size();
//         int count = n;

//         for (int i = 0; i <= n; i++) {
//             count = min(count, check(i, s));
//         }

//         return count;
//     }

// private:
//     int check(int i, const string& s) {
//         int c = 0;
//         for (int j = 0; j < i; j++) {
//             if (s[j] == 'b') c++;
//         }

//         for (int j = i; j < s.size(); j++) {
//             if (s[j] == 'a') c++;
//         }

//         return c;
//     }
// };


class Solution {
public:
    int minimumDeletions(string s){
        int n = s.size();
        int b = 0;
        int count = 0;

        for(char c: s){
            if(c == 'a'){
                count = min(count+1, b);
            } else {
                b++;
            }
        }

        return count;
    }
};