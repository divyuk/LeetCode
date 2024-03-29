class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>m;
        int n = s.size();
        int ans=0;
        int left =0, maxF=0;
        for(int right =0; right < n; right++){
            m[s[right]]++;
            maxF = max(maxF,m[s[right]] );
            
            if( ((right-left +1) - maxF) > k  ){
                m[s[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};