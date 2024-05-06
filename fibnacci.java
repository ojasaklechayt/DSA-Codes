public class FibonacciMemoization {
    public static int fibonacci(int n) {
        int[] memo = new int[n + 1];
        return fibonacciHelper(n, memo);
    }

    private static int fibonacciHelper(int n, int[] memo) {
        if (n <= 1)
            return n;
        if (memo[n] == 0) {
            memo[n] = fibonacciHelper(n - 1, memo) + fibonacciHelper(n - 2, memo);
        }
        return memo[n];
    }

    public static void main(String[] args) {
        int n = 10;
        System.out.println("Fibonacci number at position " + n + ": " + fibonacci(n));
    }
}
