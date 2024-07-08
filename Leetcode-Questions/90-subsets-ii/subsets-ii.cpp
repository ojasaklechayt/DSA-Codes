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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_set<vector<int>, VectorHash> sett;
        vector<vector<int>> subsets;
        vector<int> temp;

        sort(nums.begin(), nums.end());
        rec(nums, 0, sett, temp);

        for (auto i : sett) {
            subsets.push_back(i);
        }
        return subsets;
    }

private:
    void rec(vector<int>& nums, int start, unordered_set<vector<int>, VectorHash>& sett, vector<int>& temp) {
        sett.insert(temp);

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            rec(nums, i + 1, sett, temp);
            temp.pop_back();
        }
    }
};
