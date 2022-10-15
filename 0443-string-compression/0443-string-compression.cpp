class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(),count=1;
        if(n==1) return 1;
        string s ="";
        char first = chars[0];
        for(int i =1;i<n;i++){
            if(first == chars[i]){
                count++;
               
                continue;
            }
            else{
                if(count>1){
                    s+=first+to_string(count);
                }
                else
                    s+=first;
                first = chars[i];
                count=1;
            }
        }
        if(count>1)
            s+=first+to_string(count);
        else
            s+=first;
        chars.clear();
        n = s.size();
        for(int i=0;i<n;i++){
            chars.push_back(s[i]);
        }
        return n;
    }
};