class Solution {
public:
    int specialArray(vector<int>& nums) {
        // Sort the array to facilitate binary search
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Perform binary search to find the special value x
        for (int x = 0; x <= n; ++x) {
            // Find the number of elements >= x using lower_bound
            int count = n - (lower_bound(nums.begin(), nums.end(), x) - nums.begin());
            if (count == x)  return x;
        }
        return -1;
    }
};

//[3,9,7,8,3,8,6,6] n = 8 , o/p : 6

//  0 1 2 3 4 5 6 7 
// [3 3 6 6 7 8 8 9]

// count = 8 - 2 = 6