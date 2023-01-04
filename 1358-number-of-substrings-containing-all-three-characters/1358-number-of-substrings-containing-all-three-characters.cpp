class Solution {
public:
    int numberOfSubstrings(string s) {
        int l =0;
        int r = 0;
        int len = s.size();
        map<char,int>m;
        int c =0;
        if(r>len)
            return 0;
        while(r<len){            
            m[s[r]]++;
            while(m['a'] and m['b'] and m['c'] ){
                c+=len-r;
                m[s[l++]]--;
            }
            r++;
        }
        return c;
    }
};