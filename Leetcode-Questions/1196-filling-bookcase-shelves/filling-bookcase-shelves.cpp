// class Solution {
// public:
//     int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
//         int levels = 0, height = 0, n = books.size();

//         sort(books.begin(), books.end(), [](const vector<int>&a, const vector<int>& b){
//             if(a[0] == b[0]){
//                 return a[1] < b[1];
//             }
//             return a[0]<b[0];
//         });

//         while(n!=0){
//             int tempwidth = 0;
//             int tempheight = 0;
//             for(int i=0; i<n; i++){
//                 if(tempwidth+books[i][0] <= shelfWidth){
//                     tempwidth+=books[i][0];
//                     tempheight = max(tempheight, books[i][1]);
//                     books.erase(books.begin() + i);
//                 }
//             }

//             height+=tempheight;
//             levels++;
//         }

//         return height;
//     }
// };



class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int>dp(n+1, INT_MAX);
        dp[0]=0;

        for(int i=1; i<=n; i++){
            int width = 0, height = 0;
            for(int j=i; j>0; j--){
                width+=books[j-1][0];
                if(width>shelfWidth) break;
                height = max(height, books[j-1][1]);
                dp[i] = min(dp[i], dp[j-1] + height);
            }
        }

        return dp[n];
    }
};