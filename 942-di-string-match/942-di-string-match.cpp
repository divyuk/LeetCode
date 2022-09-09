class Solution {
    public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int>ans(n+1);
        int j = n;
        int i = 0;
        int k=0;
        for(char c:s){
            ans[k] = (c=='I')?i++:j--;
            k++;
        }
        ans[n] = j;
        return ans;
    }
};