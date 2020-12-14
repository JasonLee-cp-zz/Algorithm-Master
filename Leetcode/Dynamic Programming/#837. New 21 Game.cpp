class Solution {
public:
   
  
    double new21Game(int N, int K, int W) {
      if(K==0) return 1;
        vector<double>dp(K+W,0);
        dp[0]=1.0;
        W=(double)W;
        for(int i=1; i<=K+W-1; i++){
            dp[i]=dp[i-1];
            if(i<=W){
                dp[i]+=dp[i-1]/W;
            }else{
               dp[i]+=(dp[i-1]-dp[i-W-1])/W;
            }
            if(i>K){
                dp[i]-=(dp[i-1]-dp[K-1])/W;
            }
        }
        return dp[N]-dp[K-1];
    }
};