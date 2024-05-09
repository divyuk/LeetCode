class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int totalWeight = accumulate(weights.begin(), weights.end(),0 );
        int high = totalWeight;
        int mid=0;
        int res=high;
        while(low<=high){
            
            mid=low+(high-low)/2;
            
            int ships =1, currCap = mid;
            for(int w : weights){
                if(currCap-w <0){
                    ships++;
                    currCap = mid;
                }
                currCap -=w;
            }
            if(ships<=days){
                res = min(res,mid);
                high = mid-1;
            }
            else low = mid+1;
        }
        return res;
    }
};