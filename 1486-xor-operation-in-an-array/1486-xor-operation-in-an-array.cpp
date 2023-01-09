class Solution {
public:
    int xorOperation(int n, int start) {
        // vector<int>arr;
        int num=0;
        int xr = 0;
        for(int i = 0; i<n; i++){
            num = start+2*i;
            xr^=num;
        }
        
        // for(auto i : arr){
        //     xr ^=i;
        // }
        return xr;
    }
};