class Solution {
    
    int countSteps( int i, int ringIndex, int ringLen ){
        int distance = abs(i-ringIndex);
        int wrapAround = ringLen - distance;
        return min(distance , wrapAround);
    }
    
    int solve(string ring, string key, int ringLen, int keyLen,int rindex, int k, vector<vector<int>>&dp){
        
        if(k>=keyLen) return 0;
        if(dp[rindex][k] != -1) return dp[rindex][k];
        int res = INT_MAX;
        for(int i = 0; i<ringLen; i++){
            if(ring[i] == key[k]){
                int steps = 1 + countSteps(i,rindex,ringLen);
                int totalSteps = steps + solve(ring,key,ringLen,keyLen,i,k+1,dp);
                res = min(res, totalSteps);
            }
        }
        return dp[rindex][k] = res;
    }
    
public:
    int findRotateSteps(string ring, string key) {
        int ringLen = ring.size();
        int keyLen  = key.size();
//         vector<vector<int>>dp(ringLen, vector<int>(keyLen, -1));
//         return solve(ring, key, ringLen, keyLen, 0, 0, dp );
        
        
        vector<vector<int>>dp(ringLen, vector<int>(keyLen+1, INT_MAX));
        
        for(int r =0;r<ringLen;r++) dp[r][keyLen] = 0;
        
        for(int k = keyLen -1 ; k>=0 ; k--){
            for(int r = 0; r<ringLen; r++){
                int res = INT_MAX;
                for(int i = 0; i<ringLen; i++){
                    if(ring[i] == key[k]){
                        int steps = 1 + countSteps(r,i,ringLen);
                        int totalSteps = steps + dp[i][k+1];
                        res = min(res, totalSteps);
                    }
                     
                }
                dp[r][k] = res;
            }
           
        }
        return dp[0][0];
    }
};