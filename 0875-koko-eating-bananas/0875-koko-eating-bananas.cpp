class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end()), mid=0;
        int result = 0;
        
        while(low<high){
            mid = low + (high-low)/2;
            int hours = 0;
            
            for(int &p : piles){
                hours += p/mid;
                if(p%mid!=0) hours++;
            }   
            
            if(hours<=h){
                result = mid;
                high   = mid;
            }
            else low = mid+1;
        }
        return low;
    }
};