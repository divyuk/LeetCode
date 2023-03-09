class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sumtillhere =0, memory=nums[0];
        for(int i : nums){
            if(sumtillhere<0)
                sumtillhere = 0;
            sumtillhere+=i;
            if(sumtillhere>memory)
                memory=sumtillhere;
        }
        return memory;
    }
};