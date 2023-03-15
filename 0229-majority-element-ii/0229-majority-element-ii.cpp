class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 =0,x1=-1,c2=0,x2=-1,n=nums.size();
        vector<int>ans;
        for(int i : nums){

            if(i==x1)c1++;
            else if(i==x2)c2++;

            else if(c1==0){
                x1 = i;
                c1++;
            }
            else if(c2==0){
                x2=i;
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
            //! Perform a check to see if x1 and x2 are grater than n/3;

            int me = n/3,m1=0,m2=0;
            for(int i =0;i<n;i++){
                if(nums[i] == x1)
                    m1++;
                else if(nums[i] == x2)
                    m2++;
            }
            if(m1>me)
                ans.push_back(x1);
            if(m2>me)
                ans.push_back(x2);

        return ans;
        }
};