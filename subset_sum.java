public class SubsetSumRecursive {

    public static boolean subsetSum(int[] nums, int target) {
        return subsetSumHelper(nums, nums.length - 1, target);
    }

    private static boolean subsetSumHelper(int[] nums, int index, int target) {
        // Base cases
        if (target == 0) {
            return true; // Subset with sum 0 is always achievable
        }
        if (index < 0 || target < 0) {
            return false; // If we have exhausted all elements or target becomes negative
        }
        
        // If the current element is greater than the target, we skip it
        if (nums[index] > target) {
            return subsetSumHelper(nums, index - 1, target);
        }
        
        // Two possibilities:
        // 1. Include the current element and check if the subset sum is achievable
        // 2. Exclude the current element and check if the subset sum is achievable
        return subsetSumHelper(nums, index - 1, target - nums[index]) || subsetSumHelper(nums, index - 1, target);
    }

    public static void main(String[] args) {
        int[] nums = {3, 34, 4, 12, 5, 2};
        int target = 9;
        System.out.println("Subset with sum " + target + " found: " + subsetSum(nums, target));
    }
}
