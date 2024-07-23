class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> sortedval;
        unordered_map<int,int> freq;
        for(int i: nums){
            freq[i]++;
        }

        vector<pair<int,int>> freqVec(freq.begin(), freq.end());

        sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second == b.second ? a.first > b.first : a.second < b.second;
        });

        for (const auto &pair : freqVec) {
            for (int i = 0; i < pair.second; ++i) {
                sortedval.push_back(pair.first);
            }
        }

        return sortedval;
    }
};