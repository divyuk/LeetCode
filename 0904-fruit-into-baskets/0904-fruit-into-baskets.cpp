class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int>umap;
        int left = 0 , right =0, total=0, res=0;
        while(right<n){
            
            umap[fruits[right]]++;
            total++;
            
            while(umap.size() > 2){
                int fruitRemove = fruits[left];
                umap[fruitRemove]--;
                total--;
                left++;
                if(umap[fruitRemove] == 0)
                    umap.erase(fruitRemove);
            } 
            res = max(res, total);
            right++;
        }
        
        return res;
    }
};