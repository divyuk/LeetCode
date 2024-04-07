class Solution {
private:
    vector<int> nums;
    vector<int> mul;
     int n ,m;
    vector<vector<int>>dp;
public:

    int f(int i, int left){

        if(i == m) return 0;
        
        int mult  = mul[i];
        int right = n-1-(i-left);
        
        if(dp[i][left] != -1) return dp[i][left];
        
        int start = nums[left]*mult+ f(i+1, left+1);
        int end =  nums[right]*mult + f(i+1, left);
        return dp[i][left] =  max(start,end);
        
    }
    
    
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        n = nums.size();
        m = mul.size();
        this->nums=nums;
        this->mul = mul;
        dp.resize(m,vector<int>(m,-1));
        return f(0,0);
    }
};