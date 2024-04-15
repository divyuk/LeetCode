class Solution {
    bool checkValidString(string s) {
        stack<int>stk1;
        stack<int>stk2;
        for(int i =0;i<s.length() ; i++){
            char c = s[i];
            if(c == '(') stk1.push(i);
            
            else if(c == '*') stk2.push(i);
            
            
            else{
                if(!stk1.empty()) stk1.pop();
                else if(!stk2.empty()) stk2.pop();
                else return false;
            }
        }

        // ((******* this is valid as ( appears before * 
        // ****(( this is not valid
        
        while(!stk1.empty() and !stk2.empty()){
            if(stk1.top() > stk2.top() ) return false;
            stk1.pop();
            stk2.pop();
        }
        
        return stk1.empty();
    }
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n&1) return 0;
        for(int i = 0; i<n ; i++ ){
            if(locked[i] == '0') s[i] = '*';
        }
        return checkValidString(s);
    }
    
    
};
