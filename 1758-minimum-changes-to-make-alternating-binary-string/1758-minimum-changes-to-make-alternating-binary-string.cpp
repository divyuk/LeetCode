class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        
        int b=0;
        int a=0;
        for(int i=0; i<n; i++){
            if(i%2==s[i]-'0'){
                a++;
            }if(i%2!=s[i]-'0'){
                b++;
            }
        }
        
        return min(a,b);
    }
};