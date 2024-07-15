// class Solution {
// public:
//     string capitalizeTitle(string title) {
//         vector<string> words;

//         string temp = "";
//         for (int i = 0; i <= title.size(); i++) {
//             if (title[i] == ' ' || i == title.size()) {
//                 words.push_back(temp);
//                 temp = "";
//             } else {
//                 temp += title[i];
//             }
//         }

//         string result = "";
//         for (int i = 0; i < words.size(); i++) {
//             if (words[i].size() > 2) {
//                 words[i][0] = toupper(words[i][0]);
//                 for (int j = 1; j <= words[i].size(); j++) {
//                     words[i][j] = tolower(words[i][j]);
//                 }
//             } else {
//                 for (int j = 0; j <= words[i].size(); j++) {
//                     words[i][j] = tolower(words[i][j]);
//                 }
//             }
//             if (i == words.size() - 1) {
//                 result += words[i];
//             } else {
//                 result += words[i] + ' ';
//             }
//         }

//         return result;
//     }
// };

class Solution {
public:
    string capitalizeTitle(string title) {
        string result = "";
        int n = title.size();
        int i = 0;
        while(i < n){
            int j = i;
            string temp;
            while(j<n && title[j] != ' '){
                if(isupper(title[j])){
                    temp += title[j] - 'A' + 'a';
                } else {
                    temp += title[j];
                }
                j++;
            }

            if(temp.size() > 2){
                temp[0] = temp[0] - 'a' + 'A';
            }
            i = j+1;
            result+=temp + " ";
        }

        result.erase(result.end() - 1);
        return result;
    }
};