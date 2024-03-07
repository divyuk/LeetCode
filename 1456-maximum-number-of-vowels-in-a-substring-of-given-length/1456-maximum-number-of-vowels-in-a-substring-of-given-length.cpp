class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int left =0,right =0;
        int ans=0 , len=0;
        while(right<n){
            
            if(s[right] == 'a' || s[right] == 'e' || s[right] == 'i' || s[right] == 'o' ||
               s[right] == 'u')
                len++;
            
            if(right-left+1 == k){
                ans = max(ans,len);
               if(s[left] == 'a' || s[left] == 'e' || s[left] == 'i' || s[left] == 'o' ||
               s[left] == 'u')
                    len--;
                left++;
            }
            right++;
            
        }
        return ans;
    }
};