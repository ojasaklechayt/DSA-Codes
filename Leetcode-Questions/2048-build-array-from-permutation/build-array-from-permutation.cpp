class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++){
            arr[i] = nums[nums[i]];
        }

        return arr;
    }
};