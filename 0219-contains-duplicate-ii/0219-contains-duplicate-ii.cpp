class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        int ans=0;
        for(int i = 0 ; i< nums.size() ; i++){
            if(umap.find(nums[i])!=umap.end()){
                int index = umap[nums[i]];
                if(abs(index-i) <= k)
                    return true;
            } 
            umap[nums[i]] = i;
        }
        return false;
    }
};