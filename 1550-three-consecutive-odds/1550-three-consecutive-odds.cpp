class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int len = arr.size();

        for(int i = 0;i<=len-3;i++){
            if(arr[i]%2 != 0 and arr[i+1]%2 != 0 and arr[i+2]%2 != 0 ) return true;
        }
        return false;
    }
};