class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;

        int a = haystack.size();
        int b = needle.size();
        
        if(a<b) return -1;

        for(int i=0; i<=(a-b); ++i){
            int j = 0;

            while(j<b && haystack[i+j] == needle[j]){
                j++;
            }

            if(j==b) return i;
        }

        return -1;
        
    }
};