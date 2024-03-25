class Solution {
public:
    
    void combinator(int index,vector<int>& candidates, int target,vector<vector<int>>&result,int sum, vector<int>summer){
        
        if(sum == target){
            result.push_back(summer);
            return;
        }
        
        if(index >= candidates.size() or sum > target) return;
        
        summer.push_back(candidates[index]);
        
        combinator(index,candidates, target, result, sum+candidates[index],summer);
        summer.pop_back();
        combinator(index+1,candidates, target, result, sum,summer);

        return;
    }
    
    
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        combinator(0,candidates,target, result,0,{}); // index
        return result;
    }
};