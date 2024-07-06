class Solution {
public:
    int passThePillow(int n, int time) {
        int index = 1;
        int direction = 1;

        int cover = 0;
        while(cover!=time){
            index+=direction;

            if(index == n){
                direction = -1;
            } else if(index == 1){
                direction = 1;
            }

            cover++;
        }

        return index;
    }
};