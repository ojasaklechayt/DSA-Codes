class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int left = 1;
        int right = position.back() - position.front();
        int force = 0;
        while(left <= right){
            int mid = left + (right - left)/2;

            if(helper(position, m, mid)){
                force = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return force;
    }

private:
    bool helper(vector<int> position, int m, int mid){
        int count = 1;
        int first = position[0];
        for(int i=1; i<position.size(); i++){
            if(position[i] - first >= mid){
                count++;
                first = position[i];
                if(count == m) return true;
            }
        }

        return false;
    }
};