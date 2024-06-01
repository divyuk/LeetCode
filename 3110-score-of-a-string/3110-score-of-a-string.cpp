class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size();
        int i =0, j=1;
        int sum=0;
        for(;j<n;j++ , i++){
            sum += abs(s[j]- s[i]);
        }
        
        return sum;
    }
};