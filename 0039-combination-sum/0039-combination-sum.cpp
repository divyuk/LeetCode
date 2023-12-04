class Solution {
public:
    vector<vector<int>>ans;
    
    void create(int i,vector<int>&curr,vector<int>&c,int total,int target){
        if(total==target){
            ans.push_back(curr);
            return;
        }
        if(i>= c.size() or total>target) return;
        curr.push_back(c[i]);
        create(i,curr,c,total+c[i], target);
        curr.pop_back();
        create(i+1,curr,c,total, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<int>curr;
        create(0, curr,c,0,t);
        return ans;
    }
};