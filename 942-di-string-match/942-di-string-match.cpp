class Solution {
    public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int>ans(n+1);
        int inc = n,dec=0;;
        for(int i = 0;i<n;i++){
            if(s[i]=='I'){
                ans[i] = dec;
                dec++;
            }
            else{
                ans[i] = inc;
                inc--;
            }
        }
        ans[n] = inc;
        return ans;
    }
};