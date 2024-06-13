class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> mean;
        for(int num: nums) {
            mean.push(num);
            if(mean.size() > k){
                mean.pop();
            }
        }

        return mean.top();
    }
};