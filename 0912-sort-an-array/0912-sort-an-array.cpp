class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void mergeSort(vector<int>& nums, int left, int right) {
        // Base case: if the subarray has one or zero elements, it is already sorted
        if (left >= right) return;
        
        // Divide: find the midpoint to split the array into two halves
        int mid = left + (right - left) / 2;
        
        // Conquer: recursively sort the left and right halves
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        
        // Combine: merge the sorted halves
        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        // Create temporary arrays to hold the left and right halves
        vector<int> leftArray(n1);
        vector<int> rightArray(n2);
        
        // Copy data to temporary arrays
        for (int i = 0; i < n1; ++i)
            leftArray[i] = nums[left + i];
        for (int i = 0; i < n2; ++i)
            rightArray[i] = nums[mid + 1 + i];
        
        // Initial indices for left, right, and merged subarrays
        int i = 0, j = 0, k = left;
        
        // Merge the temporary arrays back into the original array
        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                nums[k++] = leftArray[i++];
            } else {
                nums[k++] = rightArray[j++];
            }
        }
        
        // Copy any remaining elements of leftArray
        while (i < n1) {
            nums[k++] = leftArray[i++];
        }
        
        // Copy any remaining elements of rightArray
        while (j < n2) {
            nums[k++] = rightArray[j++];
        }
    }
};