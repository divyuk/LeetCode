class Solution {
public:
    void create(int pos ,vector<int>& nums,vector<int>&temp,vector<vector<int>>&res){
        res.push_back(temp);
        for(int i= pos ; i<nums.size() ; i++){
            if(i!=pos and nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            create(i+1,nums,temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>res;
        sort(nums.begin() , nums.end());
        create(0,nums,temp,res);
        return res;
    }
};