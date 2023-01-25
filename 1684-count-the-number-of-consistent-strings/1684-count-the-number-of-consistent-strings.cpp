class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>arr(26,0);
        for(int i = 0 ;i< allowed.size() ; i++){
            arr[allowed[i] - 'a']++;
        }
        int c=0;
        bool flag =true;
        for(auto s : words){
            for(int i = 0 ;i< s.size() ; i++){
                if(arr[s[i]-'a'] ==0){
                    flag=false;
                    break;
                }
            }
            if(flag)
                c++;
            flag=true;
        }
        
        return c;
    }
};