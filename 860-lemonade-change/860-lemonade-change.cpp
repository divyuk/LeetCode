class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int arr[3];
        memset(arr,0,sizeof(arr));
        for(int i : bills){
            if(i==5)
                arr[0]++;

            else if(i==10){
                arr[1]++;
                if(arr[0]!=0)
                    arr[0]--;
                else
                    return false;
            }
            else{
                arr[2]++;
                if(arr[0]!=0 and arr[1]!=0)
                    arr[0]--,arr[1]--;
                else if(arr[0]>=3)
                    arr[0]-=3;
                else
                    return false;
            }
        }
        return true;
    }
};