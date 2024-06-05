// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> two;
//         findTwoSum(nums, two, target, 0, 0);
//         return two;
//     }

// private:
//     bool findTwoSum(vector<int>& nums, vector<int>& two, int target, int
//     index, int sum) {
//         if (index >= nums.size() || two.size() == 2) {
//             return sum == target && two.size() == 2;
//         }

//         two.push_back(index);
//         if (findTwoSum(nums, two, target, index + 1, sum + nums[index])) {
//             return true;
//         }
//         two.pop_back();
//         if (findTwoSum(nums, two, target, index + 1, sum)) {
//             return true;
//         }

//         return false;
//     }
// };


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> visited;
        int len = nums.size();
        for(int i=0; i<len; i++){
            int n = nums[i];
            int complement = target - n;
            if(visited.count(complement)){
                return {visited[complement], i};
            }
            visited[n] = i;
        }
        return {};
    }
};

