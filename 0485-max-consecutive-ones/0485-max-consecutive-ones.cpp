class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l =0;
        int r = nums.size();
        int c = 0,ans=0;
        while(l<nums.size()){  
            if(nums[l] == 1)
                c++;
            else{
               
                c=0;
            }
            
            l++;
             ans = max(ans , c);
        }
        return ans;
    }
};