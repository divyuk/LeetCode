class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string>ans(n);
        const int M = *max_element(score.begin(), score.end());
        vector<int>mp(M+1, -1);
        for(int i =0; i< n; i++) mp[score[i]] = i; // score got by which player
        
        int rank =1;
        for(int i = M; i>=0; i--){
            if(mp[i] != -1){
                int ath = mp[i];
                if(rank == 1) ans[ath] = "Gold Medal";
                else if(rank == 2) ans[ath] = "Silver Medal";
                else if(rank == 3) ans[ath] = "Bronze Medal";
                else ans[ath] = to_string(rank);
                rank++;
            }
        }
    return ans;
    }
};