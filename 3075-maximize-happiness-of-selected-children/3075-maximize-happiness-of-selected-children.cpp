class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long ans = 0;
        int n = h.size();
        sort(h.begin() , h.end() , greater<int>());
        ans+=h[0];
        int sel=0;
        for(int i =1 ;i<k;i++){
            if(h[i]-1-sel>0) ans+=h[i]-1-sel;
            else break;
            sel++;
                
        }
        return ans;
    }
};