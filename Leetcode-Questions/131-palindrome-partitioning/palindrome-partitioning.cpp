class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;

        partitionHelper(s, 0, current, result);
        return result;
    }

private:
    void partitionHelper(const string& s, int start,
                         vector<string>& current,
                         vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (palindromic(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                partitionHelper(s, end + 1, current, result);
                current.pop_back();
            }
        }
    }
    bool palindromic(string s, int start, int end) {

        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};
