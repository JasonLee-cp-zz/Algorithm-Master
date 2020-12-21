class Solution {
public:
   
    int coinChange(vector<int>& coins, int amount) {
       vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){
                if(coins[j]>i)continue;
                if(dp[i-coins[j]]==INT_MAX) continue;
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
        return dp[amount]==INT_MAX ? -1 : dp[amount];
    }
};

//Alternate
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+1,0);
        
        for(int i=1; i<=amount; i++){
            int min_coin = INT_MAX;
            for(int j=0; j<n; j++){
                if(coins[j]>i) continue;
               min_coin=min(min_coin,dp[i-coins[j]]);
            }
            if(min_coin!=INT_MAX) min_coin++;
            dp[i]=min_coin;
        }
        
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};