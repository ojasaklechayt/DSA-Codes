class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total_customer = customers.size();
        double total_wait = customers[0][1], total_time = customers[0][1];
        double t_time = customers[0][0] + customers[0][1];

        for(double i=1; i<total_customer; i++){
            if(t_time >= customers[i][0]){
                t_time += customers[i][1];
                total_wait = t_time - customers[i][0];
            } else {
                t_time = customers[i][0] + customers[i][1];
                total_wait = customers[i][1];
            }
            total_time += total_wait;
        }

        double avg_time = total_time/total_customer;

        return avg_time;
    }
};