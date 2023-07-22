class Solution {
public:
    bool isVowel(char c) {
    
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    string sortVowels(string s) {
        int n = s.size();
        string temp="";
        vector<string>ans(n, "9");
        for(int i =0 ; i < n; i++){
            if(!isVowel(s[i]))
                ans[i] = s[i];
            else
                temp+=s[i];
        }
        
        sort(temp.begin(), temp.end());
        for(int i =0 ; i < n; i++){
            cout<<ans[i];
        }
        int j=0;
        for(int i =0 ; i < n; i++){
            if(ans[i]=="9")
                ans[i] = temp[j++];
        }
        
    string result;
    for (string& str : ans) {
        result += str;
    }
    return result;
        
    }
};