class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        int ans=0;bool flag = false;
        for(int i = 0; i<n; i++){
            char c = s[i];
            for(int j =i+1;j<n;j++){
                char d = s[j];
                if(c == d and j-i>=1) {
                    ans = max(ans , j-i-1);
                    flag = true;
                }
            }
        }
        if(flag == false) return -1;
        return ans;
    }
};