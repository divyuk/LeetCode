class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c =0,r=0;
        for(int i =0;i<nums.size() ; i++){
            if(c==0)
                r=nums[i];
            nums[i]==r?c++:c--;
        }
        return r;
    }
};