class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize the memoization vector
        // Dimensions: n (days) x 2 (canBuy state) x 3 (number of transactions + 1)
        vector<vector<vector<int>>> memo(
            prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        
        // Start the recursive function from day 0, with the option to buy and 2 transactions remaining
        return f(0, prices, true, 2, memo);
    }

private:
    int f(int index, vector<int>& prices, bool canBuy, int cap,
          vector<vector<vector<int>>>& memo) {
        
        // Base case: If we reach the end of the price list or run out of transaction capacity
        if (index == prices.size() || cap == 0)
            return 0;

        // If the subproblem has already been solved, return the stored result
        if (memo[index][canBuy][cap] != -1)
            return memo[index][canBuy][cap];

        // If we are in a state where we can buy
        if (canBuy) {
            // Choice to buy the stock at the current price or skip buying
            // Buying the stock: Subtract the current price from the total profit and move to the next day in the 'cannot buy' state
            // Skipping buying: Move to the next day in the 'can buy' state
            memo[index][canBuy][cap] =
                max(-prices[index] + f(index + 1, prices, false, cap, memo),
                    f(index + 1, prices, true, cap, memo));
        } else {
            // If we are in a state where we can sell
            // Choice to sell the stock at the current price or skip selling
            // Selling the stock: Add the current price to the total profit, decrement the transaction capacity, and move to the next day in the 'can buy' state
            // Skipping selling: Move to the next day in the 'cannot buy' state
            memo[index][canBuy][cap] =
                max(prices[index] + f(index + 1, prices, true, cap - 1, memo),
                    f(index + 1, prices, false, cap, memo));
        }

        // Return the result for the current subproblem
        return memo[index][canBuy][cap];
    }
};
