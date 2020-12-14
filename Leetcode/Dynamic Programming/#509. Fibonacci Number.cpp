class Solution {
public:
    int fibonacci(int n, vector<int>&dp){
        if(n==0) return 0;
        if(n==1) return 1;
        if(dp[n]) return dp[n];
        dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
        return dp[n];
    }
    int fib(int N) {
        vector<int>dp(N+1,0);
        return fibonacci(N,dp);
    }
};