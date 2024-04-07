class Solution {
public:
    bool checkValidString(string s) {
        stack<int>stk1;
        stack<int>stk2;
        for(int i =0;i<s.length() ; i++){
            char c = s[i];
            if(c == '('){
                stk1.push(i);
            }
            else if(c == '*'){
                stk2.push(i);
            }
            
            else{
                if(!stk1.empty())
                    stk1.pop();
                else if(!stk2.empty())
                    stk2.pop();
                else return false;
            }
        }
        // ((()))***
        
        // ((*******
        
        while(!stk1.empty() and !stk2.empty()){
            if(stk1.top() > stk2.top() ) return false;
            stk1.pop();
            stk2.pop();
        }
        
        // if(stk1.size() == stk2.size()  or (stk2.size()!=0 and stk1.size() ==0 ) ) return true;
        
        return stk1.empty();
    }
};