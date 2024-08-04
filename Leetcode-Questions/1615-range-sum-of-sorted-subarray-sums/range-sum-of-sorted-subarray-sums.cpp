class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sortedsum;

        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum+=nums[j];
                sortedsum.push_back(sum);
            }
        }

        sort(sortedsum.begin(), sortedsum.end());

        int rangesum = 0;
        for(int i=left-1; i<right; ++i){
            rangesum+=sortedsum[i];
            rangesum %= 1000000007;
        }

        return rangesum;
    }
};
