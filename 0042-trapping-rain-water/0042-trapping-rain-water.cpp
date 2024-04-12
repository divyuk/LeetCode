#include <vector>

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) 
            return 0; // Not enough bars to trap water
        

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int trappedWater = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = max(leftMax, height[left]);
                trappedWater += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                trappedWater += rightMax - height[right];
                right--;
            }
        }

        return trappedWater;
    }
};
