class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans=0;
        for(auto &s:sentences){
            int count =0;
            for(auto &c:s){
                if(c==' ')
                    count++;
            }
            ans=max(ans,count+1);
        }
        return ans;
    }
};