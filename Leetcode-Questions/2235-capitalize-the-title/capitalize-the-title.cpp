class Solution {
public:
    string capitalizeTitle(string title) {
        vector<string> words;

        string temp = "";
        for (int i = 0; i <= title.size(); i++) {
            if (title[i] == ' ' || i == title.size()) {
                words.push_back(temp);
                temp = "";
            } else {
                temp += title[i];
            }
        }

        string result = "";
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() > 2) {
                words[i][0] = toupper(words[i][0]);
                for (int j = 1; j <= words[i].size(); j++) {
                    words[i][j] = tolower(words[i][j]);
                }
            } else {
                for (int j = 0; j <= words[i].size(); j++) {
                    words[i][j] = tolower(words[i][j]);
                }
            }
            if (i == words.size() - 1) {
                result += words[i];
            } else {
                result += words[i] + ' ';
            }
        }

        return result;
    }
};