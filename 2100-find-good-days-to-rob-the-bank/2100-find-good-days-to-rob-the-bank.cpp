class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int>good;
        int n = size(security);
        vector<int>dec_left(n,0),inc_right(n,0);
        for(int i = 1 ;i<n; i++){
            if(security[i-1]>=security[i])
                dec_left[i] = dec_left[i-1]+1;
        }
        for(int i = n-2 ;i>=0; i--){
            if(security[i]<=security[i+1])
                inc_right[i] = inc_right[i+1]+1;
        }
        for (int i = time; i < n-time; i++)
        {
            if(dec_left[i]>=time and inc_right[i]>=time)
                good.push_back(i);
        }
        return good;    
    }
};