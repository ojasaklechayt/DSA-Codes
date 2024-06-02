class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        vector<int> majority;

        for(int i: nums){
            count[i]++;
        }

        int trihalf = nums.size()/3;

        for(auto& c: count){
            if(c.second > trihalf){
                majority.push_back(c.first);
            }
        }

        return majority;
    }
};