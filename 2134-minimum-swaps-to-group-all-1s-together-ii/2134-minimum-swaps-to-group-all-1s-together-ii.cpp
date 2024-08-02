class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int op1 = minSwapsHelper(nums, 0);  // Grouping all 0s together
        int op2 = minSwapsHelper(nums, 1);  // Grouping all 1s together
        return min(op1, op2);
    }

    int minSwapsHelper(vector<int>& data, int val) {
        int length = data.size();
        int totalValCount = 0;

        // Count the total number of `val` in the array
        for (int i = length - 1; i >= 0; i--) 
            if (data[i] == val) totalValCount++;
       
        if (totalValCount == 0 || totalValCount == length) return 0;

        int start = 0, end = 0;
        int maxValInWindow = 0, currentValInWindow = 0;


        while (end < totalValCount) {
            if (data[end++] == val) currentValInWindow++;
        }
        maxValInWindow = max(maxValInWindow, currentValInWindow);

        while (end < length) {
            if (data[start++] == val) currentValInWindow--;
            if (data[end++] == val) currentValInWindow++;
            maxValInWindow = max(maxValInWindow, currentValInWindow);
        }

        return totalValCount - maxValInWindow;
    }
};