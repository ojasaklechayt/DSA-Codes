class Solution {
public:
    int divide(int dividend, int divisor) {
        // Special cases
        if (divisor == 0) return INT_MAX; // Division by zero is undefined
        if (dividend == 0) return 0;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; // Overflow case

        // Determine the sign of the result
        bool sign = (dividend < 0) == (divisor < 0);

        // Convert both numbers to long long to avoid overflow
        long long n = abs((long long)dividend);
        long long m = abs((long long)divisor);

        // Perform the division using bit manipulation
        long long result = 0;
        while (n >= m) {
            int count = 0;
            while (n >= (m << (count + 1))) {
                count++;
            }
            result += 1LL << count;
            n -= m << count;
        }

        // Apply the sign to the result
        result = sign ? result : -result;

        // Handle overflow
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return static_cast<int>(result);
    }
};
