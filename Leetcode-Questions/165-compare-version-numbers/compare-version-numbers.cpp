class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = parseVersion(version1);
        vector<int> v2 = parseVersion(version2);
        
        int size = max(v1.size(), v2.size());
        
        for (int i = 0; i < size; ++i) {
            int num1 = (i < v1.size()) ? v1[i] : 0;
            int num2 = (i < v2.size()) ? v2[i] : 0;
            
            if (num1 > num2) {
                return 1;
            } else if (num1 < num2) {
                return -1;
            }
        }
        
        return 0;
    }
    
private:
    vector<int> parseVersion(const string& version) {
        vector<int> result;
        stringstream ss(version);
        string token;
        
        while (getline(ss, token, '.')) {
            result.push_back(stoi(token));
        }
        
        return result;
    }
};
