class Solution {
public:
   int minPatches(vector<int> nums, int n) {
        int patches = 0, i = 0;
        long long miss = 1; // use long to avoid integer overflow error
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) // miss is covered
                miss += nums[i++];
            else { // patch miss to the array
                miss += miss;
                patches++; // increase the answer
            }
        }
        return patches;
    }
};