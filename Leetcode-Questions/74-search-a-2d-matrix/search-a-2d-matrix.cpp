class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for(auto i: matrix){
            for(int j: i){
                if(j == target) return true;
            }
        }

        return false;
    }
};