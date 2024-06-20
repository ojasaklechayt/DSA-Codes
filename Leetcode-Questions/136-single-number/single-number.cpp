class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int it: nums){
            freq[it]++;
        }

        int single;
        for(auto& it: freq){
            if(it.second == 1){
                single = it.first; 
            }
        }

        return single;
    }
};