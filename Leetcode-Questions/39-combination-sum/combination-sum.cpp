struct VectorHash {
    std::size_t operator()(const std::vector<int>& v) const {
        std::size_t seed = 0;
        for (int i : v) {
            seed ^=
                std::hash<int>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sum;
        unordered_set<vector<int>, VectorHash> set;

        vector<int> temp;
        rec(candidates, 0, target, set, temp);

        for (auto i : set) {
            sum.push_back(i);
        }

        return sum;
    }

private:
    void rec(vector<int>& candidates, int start, int target, unordered_set<vector<int>, VectorHash>& set, vector<int>& temp,int sum = 0) {
        if(sum == target){
            set.insert(temp);
            return;
        }

        if (sum > target) {
            return;
        }
        
        for(int i=start; i<candidates.size(); i++){
            if(i>start && candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            rec(candidates, i, target, set, temp, sum+candidates[i]);
            temp.pop_back();
        }
    }
};