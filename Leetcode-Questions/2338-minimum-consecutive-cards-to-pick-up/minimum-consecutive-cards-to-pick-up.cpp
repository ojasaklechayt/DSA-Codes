class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();

        unordered_map<int, int> freq;
        int minDistance = INT_MAX;
        for(int i=0; i<n; i++){
            if(freq.find(cards[i])!=freq.end()) {
                int distance = i-freq[cards[i]]+1;
                minDistance = min(minDistance, distance);
            }
            freq[cards[i]] = i;
        }

        return (minDistance == INT_MAX) ? -1 : minDistance;
    }
};