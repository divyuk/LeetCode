class Solution {
public:
    static int counter(int k){
        int c=0;
        while(k){
            k = k & (k-1);
            c++;
        }
        return c;
    }
    static bool co(int& a , int& b){
        int c1 = counter(a);
        int c2 = counter(b);  
        if(c1 == c2)    
            return a<b;
        return c1<c2; 
    }
    vector<int> sortByBits(vector<int> arr) {
        sort(arr.begin(),arr.end(),&Solution::co);
        return arr;
    }
};