
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int i : nums) cout<<i<<" ";
        int n = nums.size();
        int i = 0;

        while (i < n) {
            vector<int> currentArray;
            int j = i;

            // Build each subarray with exactly three elements
            while (j < n && currentArray.size() < 3) {
                if (currentArray.empty() || nums[j] - currentArray.back() <= k and nums[j] - currentArray[0] <=k) {
                    currentArray.push_back(nums[j]);
                } else {
                    // If the difference condition is not satisfied, it cannot form a valid array
                    return {};
                }
                j++;
            }

            if (currentArray.size() != 3) {
                // If the size is not exactly 3, it cannot form a valid array
                return {};
            }

            // Add the current array to the result
            result.push_back(currentArray);

            i = j; // Move to the next element after the current array
        }

        // Check if there are any remaining elements that couldn't form a valid array
        if (i < n) {
            return {};
        }

        return result;
    }
};
