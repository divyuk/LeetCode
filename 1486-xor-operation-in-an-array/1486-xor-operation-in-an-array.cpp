class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>arr;
        for(int i = 0; i<n; i++){
            arr.push_back(start+2*i);
        }
        int xr = 0;
        
        for(auto i : arr){
            xr ^=i;
        }
        return xr;
    }
};