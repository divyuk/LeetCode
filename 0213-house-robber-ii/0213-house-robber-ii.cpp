class Solution {
public:
    int f( vector<int>&nums ){
        int prev = nums[0], prev2 =0, curr = 0;
        for(int i = 1 ;i<nums.size(); i++){
            long long pick = nums[i] +  prev2;
            long long notPick = 0 + prev;
            curr = max(pick, notPick);
            prev2 =prev;
            prev = curr;
            
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int  >temp1,temp2;
        vector<int > dp(n+1,-1);
        for(int i = 0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(f( temp1) , f( temp2));
    }
};