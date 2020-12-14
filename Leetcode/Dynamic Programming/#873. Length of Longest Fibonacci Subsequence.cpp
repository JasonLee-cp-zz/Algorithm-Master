class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
       int n = A.size(), res=2;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++) mp[A[i]]=i;
        vector<vector<int>>dp(n,vector<int>(n,2));
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(mp.count(A[i]+A[j])){
                    dp[j][mp[A[i]+A[j]]]=dp[i][j]+1;
                    res=max(res,dp[i][j]+1);
                }
            }
        }
        return res==2?0:res;
    }
};

