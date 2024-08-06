class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq, valuemap;
        
        for(char c : word) {
            freq[c]++;
        }

        vector<pair<char, int>> vec(freq.begin(), freq.end());

        sort(vec.begin(), vec.end(),
             [](const pair<char, int>& a, const pair<char, int>& b) {
                 return a.second > b.second;
             });

        int i = 0, mul = 1;

        for(int j = 0; j < vec.size(); j++) {
            if(i == 8) {
                mul++;
                i = 0;
            }

            valuemap[vec[j].first] = 1 * mul;
            i++;
        }

        int total = 0;
        for(char c : word) {
            total += valuemap[c];
        }

        return total;
    }
};