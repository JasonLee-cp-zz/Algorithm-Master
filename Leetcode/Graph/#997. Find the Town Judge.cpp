class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>degree(n+1,0);
        
        // town judge => indegree - outdegree = N - 1
        // outdegree -> -1, indegree -> +1
        
        for(auto t: trust){
            degree[t[0]]--;
            degree[t[1]]++;
        }
        
        for(int i=1; i<n+1; i++){
            if(degree[i] == n - 1) return i;
        }
        
        return -1;
    }
};