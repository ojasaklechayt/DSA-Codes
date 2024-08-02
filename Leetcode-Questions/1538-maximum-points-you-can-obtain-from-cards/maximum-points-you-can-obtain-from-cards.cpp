class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), total = 0, maxsum = 0;

        for(int i=0; i<k; i++){
            total+=cardPoints[i];
        }

        maxsum = total;

        for(int i=0; i<k; i++){
            total = total - cardPoints[k-1-i] + cardPoints[n-1-i];
            maxsum = max(maxsum, total);
        }

        return maxsum;
    }
};