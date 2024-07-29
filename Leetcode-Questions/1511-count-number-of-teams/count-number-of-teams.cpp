// class Solution {
// public:
//     int numTeams(vector<int>& rating) {
//         int n = rating.size();
//         int count = 0;

//         for (int i = 0; i < n; i++) {
//             for (int j = i; j < n; j++) {
//                 for (int k = j; k < n; k++) {
//                     if (((rating[i] < rating[j]) && (rating[j] < rating[k]))
//                     ||
//                         ((rating[i] > rating[j]) && (rating[j] > rating[k])))
//                         {
//                             count++;
//                     }
//                 }
//             }
//         }

//         return count;
//     }
// };

// class Solution {
// public:
//     int numTeams(vector<int>& rating) {
//         int n = rating.size();
//         int count = 0;

//         for (int i = 0; i < n; i++) {
//             checkcount(rating, i, count, 1, true);
//             checkcount(rating, i, count, 1, false);
//         }

//         return count;
//     }

// private:
//     void checkcount(vector<int>& rating, int i, int& count, int temp, bool
//     increasing) {
//         if (temp == 3) {
//             count++;
//             return;
//         }

//         for(int j = i+1; j<rating.size(); j++){
//             if((increasing && rating[j] > rating[i]) || (!increasing &&
//             rating[j] < rating[i])){
//                 checkcount(rating, j, count, temp+1, increasing);
//             }
//         }
//     }
// };

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;

        for (int j = 0; j < n; j++) {
            int left_less = 0, left_more = 0;
            int right_less = 0, right_more = 0;

            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j])
                    left_less++;
                if (rating[i] > rating[j])
                    left_more++;
            }
            for (int k = j + 1; k < n; k++) {
                if (rating[k] < rating[j])
                    right_less++;
                if (rating[k] > rating[j])
                    right_more++;
            }

            count += left_less * right_more + left_more * right_less;
        }

        return count;
    }
};