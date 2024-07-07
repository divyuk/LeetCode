class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumedBottles = 0;

        while (numBottles >= numExchange) {
 
            int k = numBottles / numExchange;

            consumedBottles += numExchange *k;
            numBottles -= numExchange *k;

            numBottles +=k;
        }

        return consumedBottles + numBottles;
    }
};