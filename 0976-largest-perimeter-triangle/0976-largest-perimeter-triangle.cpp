class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        //  A triangle is valid if sum of its two sides is greater than 
        // the third side. If three sides are a, b and c, then three conditions should be met.
        sort(nums.begin() , nums.end() , greater<int>());
        int n = nums.size();
        for(int i = 0;i<nums.size()-2 ; i++){
            if(i+1<n and i+2<n){
                if(nums[i] + nums[i+1] > nums[i+2] and
                   nums[i] + nums[i+2] > nums[i+1] and
                   nums[i+1] + nums[i+2] > nums[i]){

                    double peri = (nums[i] + nums[i+1] + nums[i+2]);
                    cout<<peri<<"\n";
                    double s = peri/2;
                    cout<<nums[i]<<" "<<nums[i+1]<<" "<<nums[i+2]<<"\n";
                    double area = sqrt(s*(s-nums[i]) * (s-nums[i+1]) * (s-nums[i+2]) );
                    cout<<s<<"\n";
                    if(area != 0)
                        return peri;
                }
            }
        }
        return 0;
    }
};