class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int force = 0;
        int left = 1;
        int right = position.back() - position.front();

        // Here in binary search we are using left to get the next maximum value
        // of force with which we can place m balls with force distance, if we
        // are not able to place then, we reduce the mid value by reducing right
        // pointer by 1 position and if we are able to find, then we increase
        // left by one in hope to find the value of mid/force greater than the
        // previous
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (helper(position, m, mid)) {
                force = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return force;
    }

private:
    bool helper(vector<int>& position, int m, int mid) {
        int count = 1;
        int first = position[0];
        // Checks if we can place the m balls with distance greater than or
        // equal to mid ( which is the minimum distance ), if we are then we are
        // returning true else we are returning false
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - first >= mid) {
                count++;
                first = position[i];
                if (count == m)
                    return true;
            }
        }

        return false;
    }
};

// Important part of code that is asked in coding tests
// void main(){
//     Solution solution;
//     vector<int> position;
//     int num;
//     while(cin >> num){
//         position.push_back(num);
//     }

//     int m;
//     cin>>m;

//     int result = solution.maxDistance(position, m);
//     cout << result << endl;
// }