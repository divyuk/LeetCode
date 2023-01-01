class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin() , s.end());
        int glen = g.size();
        int slen = s.size();
        int content = 0;
        int j = 0 ;
        for(int i = 0 ; i < glen; j++ ){
            if(j == slen)
                break;
            if(s[j] >= g[i]){ // condition of content
                content++;
                i++;
            }
        }
        return content;
    }   
};