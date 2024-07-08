class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n);
        vector<char> numbers;

        for (int i = 0; i < n; i++) {
            numbers.push_back('1' + i);
        }

        factorial[0] = 1;
        for (int i = 1; i < n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }

        k--;

        string result;

        for (int i = n; i > 0; i--) {
            int idx = k / factorial[i - 1];
            k %= factorial[i - 1];

            result.push_back(numbers[idx]);
            numbers.erase(numbers.begin() + idx);
        }

        return result;
    }
};