class Solution {
private:
    std::unordered_map<int, int> points;
    std::unordered_map<int, int> cache;
    
    int maxPoints(int num) {
        // Check for base cases
        if (num == 0) {
            return 0;
        }
        
        if (num == 1) {
            return points.count(1) ? points[1] : 0;
        }
        
        if (cache.count(num)) {
            return cache[num];
        }
        
        // Apply recurrence relation
        int gain = points.count(num) ? points[num] : 0;
        cache[num] = std::max(maxPoints(num - 1), maxPoints(num - 2) + gain);
        return cache[num];
    }
    
public:
    int deleteAndEarn(std::vector<int>& nums) {
        int maxNumber = 0;
        
        // Precompute how many points we gain from taking an element
        for (int num : nums) {
            points[num] += num;
            maxNumber = std::max(maxNumber, num);
        }
        
        return maxPoints(maxNumber);
    }
};
