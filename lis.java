import java.util.Arrays;
import java.util.Scanner;

public class LongestIncreasingSubsequenceMemoization {

    public static int lis(int[] nums) {
        int[] memo = new int[nums.length];
        Arrays.fill(memo, -1);
        return lisHelper(nums, -1, 0, memo);
    }

    private static int lisHelper(int[] nums, int prevIndex, int curIndex, int[] memo) {
        if (curIndex == nums.length) {
            return 0;
        }
        if (memo[curIndex] != -1) {
            return memo[curIndex];
        }
        int taken = 0;
        if (prevIndex == -1 || nums[curIndex] > nums[prevIndex]) {
            taken = 1 + lisHelper(nums, curIndex, curIndex + 1, memo);
        }
        int notTaken = lisHelper(nums, prevIndex, curIndex + 1, memo);
        memo[curIndex] = Math.max(taken, notTaken);
        return memo[curIndex];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int n = scanner.nextInt();
        int[] nums = new int[n];

        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }

        System.out.println("Length of Longest Increasing Subsequence: " + lis(nums));

        scanner.close();
    }
}
