// class Solution {
// public:
//     int findCenter(vector<vector<int>>& edges) {
//         int n = edges.size() + 1;
//         vector<vector<int>> adjlist(n+1);
//         for(auto& i: edges){
//             adjlist[i[0]].push_back(i[1]);
//             adjlist[i[1]].push_back(i[0]);
//         } 

//         for(int i=0; i<adjlist.size(); i++){
//             int t = adjlist[i].size();
//             if(t == n-1) return i;
//         }

//         return 0;
//     }
// };


class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Check the common node between the first two edges
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
            return edges[0][0];
        } else {
            return edges[0][1];
        }
    }
};
