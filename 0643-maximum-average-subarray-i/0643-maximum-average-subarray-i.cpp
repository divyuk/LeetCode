class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left =0, right = 0,  n = nums.size(); double avg=0, ans=INT_MIN;
        while(right<n){
            avg+= nums[right];
            if(right-left+1 == k){
                
                double calc = avg/k;
                ans = max(calc, ans);
                avg-=nums[left];
                left++;
            }

            right++;
        }
        
        return ans;
    }
};