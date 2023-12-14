class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    // Target is in the left half
                    high = mid - 1;
                } else {
                    // Target is in the right half
                    low = mid + 1;
                }
            }
            // Check if the right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    // Target is in the right half
                    low = mid + 1;
                } else {
                    // Target is in the left half
                    high = mid - 1;
                }
            }
        }

        return -1; // Target not found
    }
};
