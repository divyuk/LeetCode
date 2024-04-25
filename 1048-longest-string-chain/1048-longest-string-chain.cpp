class Solution {
private:
    bool canForm(string pred, string curr) {
        int n1 = pred.size();
        int n2 = curr.size();
       
        if(n1>=n2 or n2-n1 != 1) return false;
        
        int i =0, j =0;
        while(i<n1 and j<n2){
            if(pred[i] == curr[j]) i++;
            j++;
        }
        return i==n1;
    }
    
    int solve(int idx, int prev, vector<string>&words, vector<vector<int>>&dp){
        if(idx>=words.size()) return 0;
        if(prev!=-1 and dp[idx][prev] != -1) return dp[idx][prev];
        int take =0;
        if(prev==-1 or canForm( words[prev], words[idx]))
            take = 1 + solve(idx+1, idx, words, dp);
        int notTake = solve(idx+1,prev,words, dp);
        if(prev!= -1) dp[idx][prev] = max(take,notTake);
        return max(take,notTake);
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin() , words.end(), [&](string s1 , string s2){
            return s1.size()<s2.size();
        });
//         vector<vector<int>>dp(n,vector<int>(n,-1));

//         return solve(0,-1,words, dp);
        
        
        // Bottom - up
        vector<int>dp(n, 1);
        int maxL = 1 ;
        for(int i = 0; i< n ; i++){
            for(int j = 0 ; j<i ; j++){
                
                if( canForm( words[j], words[i]) ) {
            
                    dp[i] = max(dp[i] , dp[j]+1);
                    maxL = max(maxL, dp[i]);
                }
           }
        }
        return maxL;
    }
};