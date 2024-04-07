class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNumber = 0;
        unordered_map<int, int> points;
        
        // Precompute how many points we gain from taking an element
        for (int num : nums) {
            points[num] += num;
            maxNumber = max(maxNumber, num);
        }
        
        // Base cases
        int twoBack = 0;
        int oneBack = points.count(1) ? points[1] : 0;
        
        for (int num = 2; num <= maxNumber; num++) {
            int temp = oneBack;
            oneBack = max(oneBack, twoBack + (points.count(num) ? points[num] : 0));
            twoBack = temp;
        }
        
        return oneBack;
    }
};
