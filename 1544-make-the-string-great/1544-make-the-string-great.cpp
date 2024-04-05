class Solution {
public:
    string makeGood(string s) {
        stack<char>stk;
        for(char c : s){
            if(!stk.empty() and abs(c-stk.top()) == 32 )
                stk.pop();
            else
                stk.push(c);
        }
        
        string goodString ;
        
        while(!stk.empty()){
            goodString=stk.top()+goodString;
            stk.pop();
        }
        
        return goodString;
    }
};