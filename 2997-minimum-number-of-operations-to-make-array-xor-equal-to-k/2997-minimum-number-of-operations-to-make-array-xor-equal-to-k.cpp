class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
         int xorResult = 0;

        for (int e : nums) xorResult ^= e;


        int bitwiseXOR = xorResult ^ k;
        int countBits = 0;

        while (bitwiseXOR != 0) {
            countBits += bitwiseXOR & 1;
            bitwiseXOR >>= 1;
        }

        return countBits;
    }
};