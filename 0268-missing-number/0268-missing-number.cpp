class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>h(n+1,0);
        
        for(int i = 0;i<n;i++){
            h[nums[i]]++;
        }
        
        for(int i = 0;i<n;i++)
            if(h[i] ==0)
                return i;
        return n;
    }
};