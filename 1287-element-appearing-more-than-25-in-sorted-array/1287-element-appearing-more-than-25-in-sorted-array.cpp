class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(); int c=0;
        for(int i = 1 ;i<n;i++){
            if(arr[i] == arr[i-1] ) c++;
            else c=1;
            if(c>n/4) return arr[i];
        }
        return arr[0];
    }
};