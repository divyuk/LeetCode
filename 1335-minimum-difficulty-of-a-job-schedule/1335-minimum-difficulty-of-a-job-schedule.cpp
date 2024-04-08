class Solution {
private :
    int cache[301][11];
public:
    
    int solve(vector<int>&jd, int n, int idx, int d){
        // if you are at day 1 you have to complete all the remaining job
        if(d==1)
            return *max_element(jd.begin()+idx, jd.end());
        
        if(cache[idx][d] != -1) return cache[idx][d];
        
        int maxValue = INT_MIN;
        int result = INT_MAX;
        
        /*
            Try all possibilites 
            by taking 1 job in one day
            by taking 2 jon in one day
            ...
            
        */
        
        for(int i = idx; i<=n-d ; i++){
            maxValue  = max(maxValue, jd[i]);
            result = min(result, maxValue+ solve(jd,n,i+1,d-1));
        }
        
        return cache[idx][d] = result;
    }
    
    
    
    int minDifficulty(vector<int>& jd, int d) {
        int n = jd.size();
        if(n<d) return -1;
        memset(cache, -1, sizeof(cache));
        return solve(jd,n,0,d); // 0 -> idx
        
    }
};