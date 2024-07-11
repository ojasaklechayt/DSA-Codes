class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        int left = 0;
        int right = nums.size();
        rec(nums, permutations, left, right);
        return permutations;
    }

private:
    void rec(vector<int> nums,vector<vector<int>>& permutations, int left, int right){
        if(left == right){
            permutations.push_back(nums);
            return;
        }

        for(int i=left; i<right; i++){
            swap(nums[left], nums[i]);
            rec(nums, permutations, left+1, right);
            swap(nums[left], nums[i]);
        }
    }
};