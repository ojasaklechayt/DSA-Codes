class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergedarray;
        mergearray(mergedarray, nums1, nums2);

        int n = mergedarray.size();

        if(n%2 == 0){
            return (mergedarray[n/2] + mergedarray[(n/2)-1])/2.0;
        } else {
            return mergedarray[n/2];
        }
    }

private:
    void mergearray(vector<int>& mergedarray, vector<int> nums1,
                    vector<int> nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i = 0, j = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                mergedarray.push_back(nums1[i]);
                i++;
            } else if (nums1[i] > nums2[j]) {
                mergedarray.push_back(nums2[j]);
                j++;
            } else {
                mergedarray.push_back(nums1[i]);
                mergedarray.push_back(nums2[j]);
                i++;
                j++;
            }
        }

        while (i < n) {
            mergedarray.push_back(nums1[i]);
            i++;
        }

        while (j < m) {
            mergedarray.push_back(nums2[j]);
            j++;
        }
    }
};