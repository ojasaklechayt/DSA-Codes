class Solution {
public:
    int specialArray(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        int len = nums.size();
        unordered_map<int,int> special;
        for(int i=0; i<=max;i++){
            for(int j=0; j<len; j++){
                if(nums[j]>=i){
                    special[i]++;
                }
            }
        }

        for (auto i = special.begin(); i != special.end(); i++){
            if(i->first == i->second){
                return i->first;
            }
        }

        return -1;
    }
};