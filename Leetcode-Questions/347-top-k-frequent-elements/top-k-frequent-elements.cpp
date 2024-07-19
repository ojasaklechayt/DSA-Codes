class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> freq;

        for (int i : nums) {
            freq[i]++;
        }
        
        vector<pair<int, int>> freqVec(freq.begin(), freq.end());

        sort(freqVec.begin(), freqVec.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second > b.second;
             });

        for(int i=0; i<k; i++){
            result.push_back(freqVec[i].first);
        }

        return result;
    }
};