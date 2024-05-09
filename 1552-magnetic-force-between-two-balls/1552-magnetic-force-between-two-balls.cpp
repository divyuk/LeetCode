class Solution {
    bool isPossible(vector<int>& position, int m, int mid){
        int c =1;
        int last = position[0];
        for(int i = 1 ;i<position.size(); i++){
            if(position[i] - last >=mid){
                c++;
                last = position[i];
               
            }
             if(c>=m) return 1;
        }
        return 0;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int low = 1;
        sort(position.begin(),position.end());
        int high = position[position.size()-1] - position[0];
        int mid =0;
        int res =0;
        while(low<=high){
            mid =  low + (high-low)/2;
            if(isPossible(position, m, mid)){
                res = mid;
                low = mid+1;
            }
            else high = mid-1;
            
        }
        return res;
    }
};