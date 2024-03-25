class Solution {
public:
    void backtrack(int start , int n , int k, vector<vector<int>> &ans,vector<int>&comb){
        
        // Basecase
        if(comb.size() == k ){
            ans.push_back(comb);
            return;
        }
        
        for(int i = start;i<=n;i++){
            comb.push_back(i);
            backtrack(i+1, n,k,ans,comb);
            comb.pop_back();
        }
        return;
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int>comb;
        backtrack(1,n,k,ans,comb);
        return ans;
    }
};