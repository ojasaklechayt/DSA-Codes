class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = t.size();
        int m = s.size();
        int j = 0;

        for (int i = 0; i < m && j < n; i++) {
            if (s[i] == t[j]) {
                j++;
            }
        }

        return n - j;
    }
};
