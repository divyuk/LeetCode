class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Think that the number will lie in between [1,len(nums)+1]
        // No need of negative numbers so make them 1.
        // Why 1 because 1 is smallest positive number and we will check if it exist before hand.
        
        bool containsOne = false;
        int n = nums.size();
        
        for(int& num : nums){
            if(num ==1 ) containsOne= true;
            if(num<=0 or num>n) num = 1;
        }
        if(!containsOne) return 1;
        
        for(int i =0;i<n;++i){
            int val = abs(nums[i]);
            int idx = val-1;
            if(nums[idx] < 0) continue;
            nums[idx] *=-1;
        }
        
        for(int i =0; i<n; i++){
            if(nums[i]>0) return i+1;
        }
        return n+1;
    }
};