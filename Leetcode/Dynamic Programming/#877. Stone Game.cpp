//topdown approach O(n^2)
class Solution {
public:
    vector<vector<int>>dp;
    int win(int i, int j, vector<int>&piles){
        if(i==j) return piles[i];
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j]=max(piles[i]-win(i+1,j,piles),piles[j]-win(i,j-1,piles));
        return dp[i][j];
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n,vector<int>(n,-1));
        return win(0,n-1,piles)>0;
    }
};

//bottom-up O(n^2)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0; i<n; i++){
            dp[i][i]=piles[i];
        }
        for(int len=2; len<=n; len++){
            for(int i=0; i<=n-len; i++){
                int j = i+len-1;
                dp[i][j]=max(piles[i]-dp[i+1][j],piles[j]-dp[i][j-1]);
            }
        }
        return dp[0][n-1];
        
        
    }
};