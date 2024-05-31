class Solution {
public:
    int twoEggDrop(int n) {
        // Initialize the number of drops to 0
        int i = 1;

        // Loop to find the smallest 'i' such that the sum of the first 'i'
        // natural numbers is at least 'n' The sum of the first 'i' natural
        // numbers is given by the formula (i*(i+1))/2 This ensures we cover all
        // floors up to 'n' in the minimum number of drops
        while (((i * (i + 1)) / 2) < n) {
            // Increment 'i' to represent the next number of drops to test
            i++;
        }

        // Return the minimum number of drops required
        return i;
    }
};

/*
Theory and Induction Explanation:

The goal is to minimize the maximum number of drops required to find the
critical floor in the worst case using two eggs for a building with 'n' floors.

Theory:
1. Sum of Natural Numbers: The sum of the first 'i' natural numbers is given by
the formula: S_i = (i * (i + 1)) / 2 This sum represents the cumulative number
of floors we can check using 'i' drops.

2. Minimizing the Worst Case: We need to find the smallest 'i' such that the sum
S_i is at least 'n'. This ensures that in the worst-case scenario, we can
determine the critical floor within 'i' drops.

Induction Proof:
1. Base Case:
   - For n = 1, the minimum number of drops required is 1, which satisfies the
condition as S_1 = 1.
   - For n = 2, the minimum number of drops required is 2, which satisfies the
condition as S_2 = 3.

2. Inductive Step:
   - Assume that for a building with 'k' floors, the minimum number of drops
required is 'm' such that S_m >= k.
   - For a building with 'k+1' floors, we need to find the minimum number of
drops 'm+1' such that S_(m+1) >= k+1.
   - The sum of the first 'm+1' natural numbers is:
     S_(m+1) = ((m + 1) * (m + 2)) / 2
   - We need this sum to be greater than or equal to k+1:
     ((m + 1) * (m + 2)) / 2 >= k+1

Therefore, the smallest 'i' that satisfies (i * (i + 1)) / 2 >= n gives the
minimum number of drops required in the worst case. This 'i' is the answer
returned by the function.
*/
