class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int ans=0;
        int i = 0;
        int n = height.size();
        int j = n-1;
        while(i<j){
            if(height[i]<=height[j]){
                area = height[i] * (j-i);
                i++;
            }
            else{
                area = height[j] * (j-i);
                j--;
            }
            ans = max(area , ans);
        }
        return ans;
    }
};