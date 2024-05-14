class Solution {
private :
    int res= INT_MAX;
    void backTrack(int idx, vector<int>& cookies, int k, vector<int>&c){
        if(idx == cookies.size()){
            int maxCookies = *max_element(c.begin(), c.end());
            res = min(res,maxCookies);
            return;
        }
        for(int i = 0; i< k; i++){
            c[i] += cookies[idx];
            backTrack( idx+1, cookies, k, c );
            c[i] -= cookies[idx];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>c(k,0);
        
        backTrack(0, cookies, k, c);
        
        return res;
    }
};