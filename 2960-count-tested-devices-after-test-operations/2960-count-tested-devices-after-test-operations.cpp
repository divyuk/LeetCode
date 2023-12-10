class Solution {
public:
    int countTestedDevices(vector<int>& bp) {
        int n = bp.size();
        int c=0;
        for(int i =0;i<n;i++){
            int curr = bp[i];
            if(curr>0) c++;
            else continue;
            for(int j = i+1 ; j<n;j++){
                if(bp[j] >0) 
                    bp[j]-=1;
        
            } 
        }
        return c;
    }
};