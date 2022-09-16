class Solution {
public:
    string interpret(string c) {
        string ans ="";
        for(int i=0;i<c.size();i++){
            if(c[i]=='G')
                ans+='G';
            else if(c[i]=='('){
                if(c[i+1] == ')')
                    ans+='o';
                else
                    ans+="al";
            }           
        }
        return ans;
    }
};