class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Check if the number is less than or equal to 0
        // Powers of two are always positive numbers (1, 2, 4, 8, ...), so if n
        // is <= 0, it cannot be a power of two
        if (n <= 0) {
            return false;
        }

        // Use bitwise AND operation to determine if the number is a power of
        // two A power of two in binary form has exactly one bit set to '1' For
        // example: 1 -> 0001, 2 -> 0010, 4 -> 0100, 8 -> 1000, etc. When we
        // subtract 1 from a power of two, all bits after the rightmost '1' bit
        // flip For example: 4 (0100) - 1 = 3 (0011) Performing bitwise AND
        // between the number and the number minus one should yield zero if it's
        // a power of two For 4: 0100 & 0011 = 0000, which is 0 This property
        // can be used to efficiently check if n is a power of two
        return (n & (n - 1)) == 0;
    }
};
