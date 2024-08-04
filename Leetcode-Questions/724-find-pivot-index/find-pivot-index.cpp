class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pref;
        deque<pair<int,int>> pf;

        int sum = 0;
        for(int i: nums){
            sum+=i;
            pref.push_back(sum);
        }

        int posts = 0;
        for(int i=nums.size()-1; i>=0; i--){
            posts+=nums[i];
            pf.push_front({posts, i});
        }

        for(int i=0; i<pref.size(); i++){
            if(pref[i] == pf.front().first) return i;
            pf.pop_front();
        }

        return -1;
    }
};