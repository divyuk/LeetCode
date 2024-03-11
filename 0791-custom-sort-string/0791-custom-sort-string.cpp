class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char , int> umap;
        
        for(int i =0; i< s.size() ; i++) umap[s[i]]++;
        string customWord="";
        for(int i : order){
            if(umap.find(i) != umap.end() ){
                while(umap[i] != 0){
                customWord+=i;
                umap[i]--;
                }
            }
            
        }
        cout<<customWord<<"\n";
        for( auto it : umap){
            if(it.second>0){
                while(it.second!=0){
                    customWord+=it.first;
                    it.second--;
                }
            }
                
        }
            
            
        return customWord;
    }
};