class Solution {
public:
    
    void combinator(int start, int k,int target ,vector<vector<int>>&result, int sum, vector<int>summer ){
        
        // Base case
        if(sum==target and summer.size() == k){
            result.push_back(summer);
            return;
        }
        
        if(sum>target or summer.size() > k) return;
        
        for(int i = start; i<=9; i++){
    
            summer.push_back(i);
            combinator(i+1,k,target,result,sum+i,summer);
            summer.pop_back();
               
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>result;
        combinator(1,k,n,result,0, {});
        return result;
    }
};