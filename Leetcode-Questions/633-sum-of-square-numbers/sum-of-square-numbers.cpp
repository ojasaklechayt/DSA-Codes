// class Solution {
// public:
//     bool judgeSquareSum(int c) {
//         for(int i=1; i<c; i++){
//             for(int j=1; j<c; j++){
//                 if(((i*i)+(j*j)) == c) return true;
//             }
//         }

//         return false;
//     }
// };

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long i = 0; i * i <= c; ++i) {
            int j = c - i * i;
            int sqrt_j = static_cast<int>(sqrt(j));
            if (sqrt_j * sqrt_j == j) {
                return true;
            }
        }
        return false;
    }
};