class Solution {
public:
    bool isThree(int n) {
        int def = 2;

        int temp = 0;
        for(int i=2; i<=n-1; i++){
            if(n%i==0) temp++;
        }
        
        def+=temp;

        return def==3;
    }
};