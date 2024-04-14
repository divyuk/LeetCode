class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    
    bool canMeasureWater(int x, int y, int target) {
        // If the target is greater than the sum of jug capacities, we can't measure it
        if (target > x + y) return false;
        
        // If any of the jugs has zero capacity, the other jug must have the target amount
        if (x == 0 || y == 0) return target == 0 || target == x + y;
        
        // The target amount must be divisible by the greatest common divisor of the jug capacities
        return target % gcd(x, y) == 0;
    }
};