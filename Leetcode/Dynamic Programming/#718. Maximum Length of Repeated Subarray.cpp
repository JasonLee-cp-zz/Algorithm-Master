class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(); int m = B.size();
        int res = 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(A[i-1]==B[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    res = max(res,dp[i][j]);
                }
            }
        }
        return res;
    }
};