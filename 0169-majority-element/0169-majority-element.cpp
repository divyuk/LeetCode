class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c =1,x=nums[0];
        for(int i = 1 ; i<nums.size() ; i++){
            if(x==nums[i]){
                c++;
            }
            else
                c--;
            if(c==0){
                x=nums[i];
                c++;}
        }
        return x;
    }
};