class Solution {
public:
    
    int dp[1001]={[0 ... 1000]=-1};

    bool divisorGame(int N) {
       if(N==1) return false;
        if(dp[N]!=-1) return dp[N];
        for(int i=1; i<N; i++){
            if(N%i==0){
                if(!divisorGame(N-i)){
                    dp[N]=true;
                    return dp[N];
                }
            }
        }
        dp[N]=false;
        return dp[N]; 
        
    }
};