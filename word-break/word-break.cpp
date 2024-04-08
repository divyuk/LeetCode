class Solution {
public:
    
    bool solve( int idx, string s, int n,  unordered_set<string>&dict, vector<int>&dp){
        
        if( idx == n ) return true;
        
        if(dict.find(s) != dict.end()) return true;
        
        if(dp[idx] != -1 ) return dp[idx];
        
        for(int l = 1;l<=n; l++){
            string broke = s.substr(idx,l);
            if(dict.find(broke) != dict.end() and solve(idx+l, s,n, dict,dp) )
                return dp[idx] =  true;
        }
        return dp[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string>dict(wordDict.begin(), wordDict.end());\
        vector<int>dp(n+1, -1);
        return solve(0, s, n,dict , dp);
    }
};