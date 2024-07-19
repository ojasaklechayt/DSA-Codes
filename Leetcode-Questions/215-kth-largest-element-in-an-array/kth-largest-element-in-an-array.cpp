class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> qt;
        for(int i=0; i<nums.size(); i++){
            qt.push(nums[i]);
        }

        for(int i=0; i<k-1; i++){
            qt.pop();
        }

        return qt.top();
    }
};