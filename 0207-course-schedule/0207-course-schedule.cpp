class Solution {
public:
    bool dfs(int i,vector<bool>&visited , vector<bool>& call , vector<int>adj[]){
        visited[i] = true;
        call[i] = true;
        for(auto x : adj[i]){
            if(!visited[x]){
                if(dfs(x , visited , call , adj))
                    return true;
            }
            else if(call[x])
                return true;
        }
        call[i] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<bool>visited(n,false);
        vector<bool>call(n,false);
        vector<int>adj[n];
        for(auto i : prerequisites){
            int a  = i[0];
            int b = i[1];
            adj[a].push_back(b);
        }
        for(int i = 0 ; i<n;i++){
            if(!visited[i]){
                if(dfs(i , visited , call , adj))
                    return false;
            }

        }
        return true;
    }
};