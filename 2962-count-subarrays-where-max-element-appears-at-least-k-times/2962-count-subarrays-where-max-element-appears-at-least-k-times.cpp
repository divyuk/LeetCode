class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long count = 0;
        long long maxElement = *max_element(nums.begin() , nums.end());
        int left =0;
        int right =0;
        long long c =0;
        
        while(right < n){
            
            if(nums[right] == maxElement) c++;
        

            while(c ==k){
                if(nums[left] == maxElement) c--;
                left++;
            } 
            count+=left;
            
            right++;
        }
        return count;
    }
};