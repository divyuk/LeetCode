class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Sliding window
        if(k<=1) return 0;
        int n = nums.size();
        int left =0 , right =0, product =1, count =0;;
        while( right< n){
            product*=nums[right];
            while(product>=k){
                product/=nums[left];
                left++;
            }
            
            count+=right-left+1;
            right++;
        }
        
        return count;
    }
};