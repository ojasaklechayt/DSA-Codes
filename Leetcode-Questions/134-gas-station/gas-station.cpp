// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();

//         if (n == 1) {
//             return (gas[0] >= cost[0]) ? 0 : -1;
//         }

//         for (int i = 0; i < n; i++) {
//             if (helper(gas, cost, i)) {
//                 return i;
//             }
//         }

//         return -1;
//     }

// private:
//     bool helper(vector<int>& gas, vector<int>& cost, int index) {
//         int n = gas.size();
//         int totalGas = 0;
//         int currentGas = 0;

//         for (int i = 0; i < n; i++) {
//             int j = (index + i) % n;
//             totalGas += gas[j] - cost[j];
//             currentGas += gas[j] - cost[j];

//             if (currentGas < 0) {
//                 return false;
//             }
//         }

//         return totalGas >= 0;
//     }
// };


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total = 0;
        int cur = 0;  
        int si = 0;
    

        for (int i = 0; i < n; ++i) {
            total += gas[i] - cost[i];
            cur += gas[i] - cost[i];

            if(cur < 0){
                si = i + 1;
                cur = 0;
            }
        }

        return total >= 0 ? si : -1;
    }
};
