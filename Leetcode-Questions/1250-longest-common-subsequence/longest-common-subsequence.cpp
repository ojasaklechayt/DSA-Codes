// class Solution {
// public:
//     int n, m;
//     int longestCommonSubsequence(string text1, string text2) {
//         n = text1.size(), m = text2.size();
//         return lcs(text1, text2, 0, 0);
//     }

//     int lcs(string text1, string text2, int ind1, int ind2) {
//         if(ind1 >= n || ind2 >= m){
//             return 0;
//         }

//         if (text1[ind1] == text2[ind2]) {
//             return 1 + lcs(text1, text2, ind1 + 1, ind2 + 1);
//         }

//         return max(lcs(text1, text2, ind1 + 1, ind2),
//                    max(lcs(text1, text2, ind1, ind2 + 1),
//                        lcs(text1, text2, ind1 + 1, ind2 + 1)));
//     }
// };


class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int longestCommonSubsequence(string text1, string text2) {
        n = text1.size(), m = text2.size();
        dp.resize(n, vector<int>(m, -1));
        return lcs(text1, text2, 0, 0);
    }

    int lcs(string &text1, string &text2, int ind1, int ind2) {
        if (ind1 >= n || ind2 >= m) {
            return 0;
        }

        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }

        if (text1[ind1] == text2[ind2]) {
            return dp[ind1][ind2] = 1 + lcs(text1, text2, ind1 + 1, ind2 + 1);
        }

        return dp[ind1][ind2] = max(lcs(text1, text2, ind1 + 1, ind2), 
                                    lcs(text1, text2, ind1, ind2 + 1));
    }
};
