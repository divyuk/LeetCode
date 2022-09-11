class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int count=0,ans=-1;
        int no=-1;
        if(nums.size()==0)
            return 0;
        map<int,int>u;
        for(int i =0;i<nums.size();i++)
            if(nums[i]%2==0)
               u[nums[i]]++;
        int m=0;
        for(auto it : u){
            if(it.second>m){
                m=it.second;
                no=it.first;
            }
        }
        return no;
    }
};