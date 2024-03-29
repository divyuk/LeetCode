class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>map1;
        int m = s1.size();
        int n = s2.size();
        
        for(int i = 0; i< m; i++) map1[s1[i]]++;
        
        for(int i =0; i<=n-m;i++){
            
            string s = s2.substr(i,i+m);
            map<char,int> map2;
            for(int j =0;j<m;j++) map2[s[j]]++;
            
            if(map1 == map2) return true;
            
        }
        return false;
    }
};