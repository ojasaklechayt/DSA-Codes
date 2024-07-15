class Solution {
public:
    vector<int> memo;
    vector<string> wordDict;
    string s;

    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        memo = vector(s.length(), -1);
        this->wordDict = wordDict;
        this->s = s;
        return dp(s.length() - 1);
    }

    bool dp(int i){
        if(i < 0) return true;

        if(memo[i] != -1){
            return memo[i] == 1;
        }

        for(string word: wordDict){
            int currsize = word.length();
            if(i-currsize + 1 < 0){
                continue;
            }

            if(s.substr(i - currsize + 1, currsize) == word && dp(i-currsize)){
                memo[i] = 1;
                return true;
            }
        }

        memo[i] = 0;
        return false;
    }
};
