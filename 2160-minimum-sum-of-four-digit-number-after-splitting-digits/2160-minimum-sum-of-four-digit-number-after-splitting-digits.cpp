class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        stringstream ss;
        int n = s.size();
        string a="",b="";
        sort(s.begin(),s.end());
        a += s[0];
        a += s[n-1];
        b += s[1];
        b += s[n-2];
        int n1=0 ,n2= 0;
        n1 = stoi(a);
        n2=  stoi(b);
        return n1+n2;
    }
};