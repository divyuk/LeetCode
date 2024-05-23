#include <vector>
#include <unordered_set>

class Solution {
private:
    int cnt = 0;

    void subset(int i, vector<int>& nums, int n, vector<int>& temp, int k) {
        if (i == n) {
            if (!temp.empty()) cnt++; 
            return;
        }

        // Include nums[i] if it does not violate the beautiful subset condition
        bool canInclude = true;
        for (int val : temp) {
            if (abs(val - nums[i]) == k) {
                canInclude = false;
                break;
            }
        }
        
        if (canInclude) {
            temp.push_back(nums[i]);
            subset(i + 1, nums, n, temp, k);
            temp.pop_back();
        }

        // Exclude nums[i] and move to the next element
        subset(i + 1, nums, n, temp, k);
    }

public:
    int beautifulSubsets(std::vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp;
        subset(0, nums, n, temp, k);
        return cnt;
    }
};
