#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = bloomDay.size();

        // edges case
        if (static_cast<long long>(m) * k > n) return -1;  // Use long long for m * k

        for (int i = 0; i < n; i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int low = mini;
        int high = maxi;

        while (low <= high) {
            int mid = (low + high) / 2;
            int ans = CountBouquets(bloomDay, k, m, mid);

            if (ans >= m) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low; 
    }

private:
    int CountBouquets(vector<int>& arr, int k, int m, int middle) {
        int count = 0;
        int totalBouquet = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (arr[i] <= middle) {
                count++;
            } else {
                totalBouquet += count / k;
                count = 0;
            }
        }

        totalBouquet += count / k;
        return totalBouquet;
    }
};