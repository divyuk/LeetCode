#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        // Calculate the suffix sum
        int suffixSum = 0;
        for (int i = n - 1; i >= 0; --i) {
            suffixSum += nums[i];
        }

        // Calculate the result for each element
        int prefixSum = 0;
        for (int i = 0; i < n; ++i) {
            // Calculate the suffix sum excluding the current element
            suffixSum -= nums[i];

            // Calculate the contribution to the result
            result[i] = (nums[i] * i - prefixSum) + (suffixSum - nums[i] * (n - i - 1));

            // Update the prefix sum
            prefixSum += nums[i];
        }

        return result;
    }
};
