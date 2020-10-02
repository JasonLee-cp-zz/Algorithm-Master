class Solution {
public:
    vector<int>dp;
    int topdown(int n){
        if(n==1) return 1;
        if(dp[n]) return dp[n];
        for(int i=1; i<n-1; i++)
            dp[n]+=(topdown(i)*topdown(n-i-1));
        dp[n]+= 2*topdown(n-1);
        return dp[n];
        }
    int numTrees(int n) {
        dp = vector<int>(n+1,0);
        return topdown(n);
    }
};