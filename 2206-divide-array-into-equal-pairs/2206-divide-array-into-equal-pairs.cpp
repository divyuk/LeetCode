class Solution {
public:
    bool divideArray(vector<int>& nums) {
         vector<int>v(501,0);
        for(int i = 0 ; i < nums.size() ; i++){
            v[nums[i]] ++;
        }
        for(int i = 0 ;i<501; i++){
            if(v[i] %2!=0)
                return 0;
        }
        return 1;
    }
};