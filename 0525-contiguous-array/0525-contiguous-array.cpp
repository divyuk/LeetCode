class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans=0;
        int sum=0;
        int n = nums.size();
        unordered_map<int,int>umap;
        
        for(int i = 0; i< n ; i++){
            
            if(nums[i] == 0) sum-=1;
            else sum+=1;
            
            if(sum==0) ans = i+1;
            else if(umap.find(sum) == umap.end()){
                umap[sum] = i;
            }
            else{
                ans = max(ans , i- umap[sum]);
            }
        }
        
        return ans;
    }
};