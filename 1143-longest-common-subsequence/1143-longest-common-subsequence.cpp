class Solution {
private:
    string text1; string text2;
    vector<vector<int>>dp;
public:
    int f(int i1 , int i2){
        
        if(i1<0 or i2< 0) return 0;
        
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        
        if(text1[i1] == text2[i2]) return 1 + f(i1-1,i2-1);
        
        return dp[i1][i2] = max(f( i1,i2-1 ) , f( i1-1,i2)  );
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        this->text1 = text1;
        this->text2 = text2;
        int i1 = n-1, i2 = m-1;
        dp.resize(n, vector<int>(m,-1) ); 
        return f(i1,i2);
    }
};