class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int count = 0, left = 0, right = 0, n = fruits.size();

        while (right < n) {
            basket[fruits[right]]++;
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }
            count = max(count, right - left + 1);
            right++;
        }

        return count;
    }
};