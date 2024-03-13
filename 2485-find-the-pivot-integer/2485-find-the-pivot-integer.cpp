class Solution {
public:
    int calculateSum(int start , int end){
        int sum=0;
        for(int i=start;i<=end;i++) sum+=i;
        return sum;
    }
    int pivotInteger(int n) {
        if(n==1) return n;
        int l = 1,h=n,m=0;
        int ls =0, rs=0;
        while(l<h){
            m = (l+h)/2;
            ls = calculateSum(1,m);
            rs = calculateSum(m,n);
            if(ls==rs) return m;
            else if(ls<rs) l = m+1;
            else  h =m-1;
        }
        return -1;
    }
};