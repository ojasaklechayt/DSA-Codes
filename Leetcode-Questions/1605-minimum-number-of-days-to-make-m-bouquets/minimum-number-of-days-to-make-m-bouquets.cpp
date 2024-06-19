class Solution {
public:
    bool canMakeBouquets(std::vector<int>& bloomDay, int m, int k, int64_t days) {
        int64_t bouquets = 0;
        int64_t flowers = 0;
        
        for (int i = 0; i < bloomDay.size(); ++i) {
            if (bloomDay[i] <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        
        return bouquets >= m;
    }
    
    int minDays(std::vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (static_cast<int64_t>(m) * k > n) {
            return -1;
        }
        
        int64_t left = 1;
        int64_t right = *max_element(bloomDay.begin(), bloomDay.end());
        
        while (left < right) {
            int64_t mid = left + (right - left) / 2;
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1; 
            }
        }
        
        return left;
    }
};
