class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0;

        for(int i=0; i<(n-2); i++){
            for(int j=0; j<(m-2); j++){
                if(magiccube(grid, i, j)) count++;
            }
        }

        return count;
    }

private:
    bool magiccube(vector<vector<int>>& grid, int i, int j){
        unordered_set<int> uniqnum;
        int rowsum[3] = {0}, colsum[3] = {0};
        int posdiag = 0, negdiag = 0;

        for(int x=0; x<3; x++){
            for(int y=0; y<3; y++){
                int num = grid[i+x][j+y];
                if(num < 1 || num > 9 || uniqnum.find(num)!=uniqnum.end()){
                    return false;
                }

                uniqnum.insert(num);

                rowsum[x]+=num;
                colsum[y]+=num;

                if(x==y) posdiag+=num;
                if(x+y==2) negdiag+=num;
            }
        }

        int sum = rowsum[0];
        for(int i=0; i<3; i++){
            if(sum != rowsum[i] || sum != colsum[i]) return false;
        }

        if(posdiag != sum || negdiag != sum) return false;

        return true;
    }
};