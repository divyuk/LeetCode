class Solution {
public:
    int longestContinuousSubstring(string s) {
        int i =0,j=1;
        int n = s.size();
        int king =0,warr=0;
        if(n==1)
            return 1;
        while(i<n and j<n){
            
            // if(s[j-1]+1 == s[j])
            //     continue;

            if(s[j-1]+1 != s[j]){
                warr = j-i;
                i = j;
                king = max(king,warr);
                warr=0;
            }
           
            j++;
            warr = j-i;
            
        }
        return max(king,warr);
    }
};