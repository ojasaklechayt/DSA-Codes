class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        while(true){
            total += numBottles/numExchange;
            numBottles = numBottles/numExchange + numBottles%numExchange;
            if(numBottles < numExchange){
                break;
            }
        }

        return total;
    }
};