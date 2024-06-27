class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adjlist(n+1);
        for(auto& i: edges){
            adjlist[i[0]].push_back(i[1]);
            adjlist[i[1]].push_back(i[0]);
        } 

        for(int i=0; i<adjlist.size(); i++){
            int t = adjlist[i].size();
            if(t == n-1) return i;
        }

        return 0;
    }
};