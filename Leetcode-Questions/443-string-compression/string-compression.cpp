class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int i=0;
        int count=1;

        for(int j=1; j<=n; j++){
            if(j<n && chars[j] == chars[j-1]){
                count++;
            } else {
                chars[i++] = chars[j-1];

                if(count > 1){
                    string countstr = to_string(count);
                    for(char c: countstr){
                        chars[i++] = c;
                    }
                }
                count = 1;
            }
        }

        chars.resize(i);
        return i;
    }
};