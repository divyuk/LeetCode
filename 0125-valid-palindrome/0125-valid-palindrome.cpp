class Solution {
public:
    bool isPalindrome(string s) {
        vector<char>c;
        for(char i : s){
            if((i>=65 and i<=90) or (i>=97 and i<=122) ){
                i= char(tolower(i));
                c.push_back(i);
            }
            else if(i>=48 and i<=57)
                c.push_back(i);
            
        }
        cout<<int('0')<<"\n";
        for(auto k : c)
            cout<<k<<" ";
        int n = c.size();
        int i =0,j=n-1;
        while(i<=j){
            if(c[i] != c[j])
                return 0;
            i++,j--;
        }
        return 1;
    }
};