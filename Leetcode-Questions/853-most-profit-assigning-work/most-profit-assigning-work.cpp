class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();

        vector<pair<int,int>> jobs(n);
        for(int i=0; i<n; i++){
            jobs[i] = {difficulty[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end());

        for(int i=1; i<n; i++){
            jobs[i].second = max(jobs[i].second, jobs[i-1].second);
        }

        sort(worker.begin(), worker.end());

        int total_profit = 0;
        int j = 0;

        for(int i=0; i<worker.size(); ++i){
            while(j<n && worker[i] >= jobs[j].first){
                ++j;
            }

            if(j>0){
                total_profit += jobs[j-1].second;
            }
        }

        return total_profit;
    }
};