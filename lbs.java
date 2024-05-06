public class LongestBitonicSubsequenceBruteForce {

    public static int lbs(int[] nums) {
        int maxLength = 0;
        for (int i = 0; i < nums.length; i++) {
            maxLength = Math.max(maxLength, lbsHelper(nums, i, true) + lbsHelper(nums, i, false) - 1);
        }
        return maxLength;
    }

    private static int lbsHelper(int[] nums, int currentIndex, boolean increasing) {
        int maxLength = 0;
        for (int i = currentIndex + 1; i < nums.length; i++) {
            if (increasing && nums[i] > nums[currentIndex]) {
                maxLength = Math.max(maxLength, 1 + lbsHelper(nums, i, increasing));
            } else if (!increasing && nums[i] < nums[currentIndex]) {
                maxLength = Math.max(maxLength, 1 + lbsHelper(nums, i, increasing));
            }
        }
        return maxLength;
    }

    public static void main(String[] args) {
        int[] nums = { 4, 2, 5, 9, 7, 6, 10, 3, 1 };
        System.out.println("Length of Longest Bitonic Subsequence: " + lbs(nums));
    }
}
