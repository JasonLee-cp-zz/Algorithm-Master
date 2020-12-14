class Solution {
public:
    
    
    int nthUglyNumber(int n) {
        if(n<=0) return false;
        vector<int>dp(n);
        dp[0]=1;
        int i2=0,i3=0,i5=0;
        for(int i=1; i<n; i++){
            int next = min({dp[i2]*2,dp[i3]*3,dp[i5]*5});
            if(next==dp[i2]*2) i2++;
            if(next==dp[i3]*3) i3++;
            if(next==dp[i5]*5) i5++;
            dp[i]=next;
        }
        return dp[n-1];
    }
};