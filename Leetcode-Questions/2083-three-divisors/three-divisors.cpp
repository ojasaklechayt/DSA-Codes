class Solution {
public:
    bool isThree(int n) {
        if(n<3) return false;
        
        int def = 2;

        for(int i=2; i<=n-1; i++){
            if(n%i==0) def++;
        }

        return def==3;
    }
};