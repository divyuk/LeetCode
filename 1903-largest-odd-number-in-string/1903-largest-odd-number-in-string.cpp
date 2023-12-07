class Solution {
public:
    string largestOddNumber(string num) {
        int  n = num.size();
        string ans="";
        for(int j =n-1;j>=0;j--){
            int a = num[j] - '0';
            if(a%2!=0){
                ans = num.substr(0,j+1);
                break;
            }
        }
        return ans;
    }
};