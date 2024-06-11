
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> freq;
        for (int c : arr1) {
            freq[c]++;
        }

        vector<int> sortedarray;
        for (int c : arr2) {
            while (freq[c] > 0) {
                sortedarray.push_back(c);
                freq[c]--;
            }
            freq.erase(c);
        }

        vector<int> temp;

        for (auto& c : freq) {
            while (c.second > 0) {
                temp.push_back(c.first);
                c.second--;
            }
        }

        sort(temp.begin(), temp.end());

        sortedarray.insert(sortedarray.end(), temp.begin(), temp.end());

        return sortedarray;
    }
};
