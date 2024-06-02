#include <vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    // Merge sort function
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right)
            return 0; // Base case: single element or empty array
        int mid = left + (right - left) / 2; // Calculate middle index
        int count = mergeSort(nums, left, mid) +
                    mergeSort(nums, mid + 1,
                              right); // Recursively sort left and right halves
        count +=
            countPairs(nums, left, mid, right); // Count pairs across the split
        merge(nums, left, mid, right);          // Merge the sorted halves
        return count;
    }

    // Count pairs that satisfy the condition nums[i] > 2 * nums[j]
    int countPairs(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        for (int i = left; i <= mid; ++i) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                ++j;
            }
            count += (j - (mid + 1));
        }
        return count;
    }

    // Merge two sorted arrays
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp;
        int i = left, j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                ++i;
            } else {
                temp.push_back(nums[j]);
                ++j;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            ++i;
        }

        while (j <= right) {
            temp.push_back(nums[j]);
            ++j;
        }

        for (int k = left; k <= right; ++k) {
            nums[k] = temp[k - left];
        }
    }
    // Additional comments:
    // - The mergeSort function divides the array into halves and recursively
    // sorts them.
    // - The countPairs function counts the valid pairs across the split.
    // - The merge function merges the sorted halves back together.
};
