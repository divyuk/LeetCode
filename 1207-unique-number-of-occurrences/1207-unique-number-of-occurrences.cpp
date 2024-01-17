class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int >umap;
        for(int i : arr)
            umap[i]++;
        vector<int>store(1001);
        for(auto it : umap){
            if(store[it.second] == 0)
                store[it.second]++;
            else
                return 0;
        }
        return 1;
    }
};