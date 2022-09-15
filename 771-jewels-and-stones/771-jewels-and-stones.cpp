class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int c =0;
        bool arr[58]; //from 65to 122
        memset(arr , 0 , sizeof(arr));
        for(int i =0;i<jewels.size();i++)
            arr[jewels[i]-65] = true;
        for(int i = 0 ; i<stones.size() ; i++)
            if(arr[stones[i]-65])
                c++;
        return c;
    }
};