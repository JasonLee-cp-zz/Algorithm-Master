class Solution {
public:

    int countNumbersWithUniqueDigits(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=1; i<=n; i++){
            dp[i]=9; int k=9;
            int cnt=1;
            while(cnt<i){
                dp[i]*=k;
                k--; cnt++;
            }
            dp[i]+=dp[i-1];
        }
        return dp[n];
    }
};