class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> n1;
        vector<int> n2;

        for(int i=0; i<nums1.size(); i++){
            if(std::find(nums2.begin(), nums2.end(), nums1[i]) == nums2.end()){
                if(std::find(n1.begin(), n1.end(), nums1[i]) == n1.end()){
                    n1.push_back(nums1[i]);
                }
            }
        }

        for(int i=0; i<nums2.size(); i++){
            if(std::find(nums1.begin(), nums1.end(), nums2[i]) == nums1.end()){
                if(std::find(n2.begin(), n2.end(), nums2[i]) == n2.end()){
                    n2.push_back(nums2[i]);
                }
            }
        }

        return {n1,n2};
    }
};