class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<vector<int>> result(k, vector<int>(k, 0));
        vector<vector<int>> adj1(k), adj2(k);
        vector<int> indegree1(k, 0), indegree2(k, 0);

        for(int i=0; i<rowConditions.size(); i++){
            adj1[rowConditions[i][0]-1].push_back(rowConditions[i][1]-1);
            indegree1[rowConditions[i][1]-1]++;
        }

        for(int i=0; i<colConditions.size(); i++){
            adj2[colConditions[i][0]-1].push_back(colConditions[i][1]-1);
            indegree2[colConditions[i][1]-1]++;
        }

        queue<int> q1;
        queue<int> q2;

        for(int i=0; i<k; i++){
            if(indegree1[i] == 0){
                q1.push(i);
            }

            if(indegree2[i] == 0){
                q2.push(i);
            }
        }

        vector<int> roworder, colorder;
        while(!q1.empty()){
            int top = q1.front();
            q1.pop();
            roworder.push_back(top);

            for(auto u: adj1[top]){
                indegree1[u]--;
                if(indegree1[u] == 0){
                    q1.push(u);
                }
            }
        }

        while(!q2.empty()){
            int top = q2.front();
            q2.pop();
            colorder.push_back(top);

            for(auto u: adj2[top]){
                indegree2[u]--;
                if(indegree2[u] == 0){
                    q2.push(u);
                }
            }
        }

        if (roworder.size() != k || colorder.size() != k) {
            return {}; 
        }

        vector<int> rowpos(k), colpos(k);

        for(int i=0; i<k; i++){
            rowpos[roworder[i]] = i;
            colpos[colorder[i]] = i;
        }

        for(int i=0; i<k; i++){
            result[rowpos[i]][colpos[i]] = i + 1;
        }

        return result;
    }
};