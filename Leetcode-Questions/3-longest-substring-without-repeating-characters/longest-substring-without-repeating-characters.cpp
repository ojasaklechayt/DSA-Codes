class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), length = 0;

        for(int i=0; i<n; i++){
            unordered_set<char> hs;
            for(int j=i; j<n; j++){
                if(hs.find(s[j]) != hs.end()){
                    break;
                }
                hs.insert(s[j]);
                length = max(length, j - i + 1);
            }
        }

        return length;
    }
};