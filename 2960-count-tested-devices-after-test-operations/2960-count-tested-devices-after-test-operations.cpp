class Solution {
public:
    int countTestedDevices(vector<int>& bP) {
        int k =0;
        for(int i:bP )
            k+=i>k;
        return k;
    }
};