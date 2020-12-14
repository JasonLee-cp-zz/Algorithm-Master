class Solution {
public:
    
    #define MODE 1000000007
   int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
   
   /* int path(int i, int j, int n){
        if(n==0){
            if(i==0 || j==0 || i==r+1 || j==c+1) return 1;
            else return 0;
        }
        if(i==0 || j==0 || i==r+1 || j==c+1){
            if(n<=move) return 1;
            else return 0;
        }
        if(dp[i][j][n]) return dp[i][j][n];
        for(int dir=0; dir<4; dir++){
            dp[i][j][n]+=path(i+dx[dir],j+dy[dir],n-1);
            dp[i][j][n]%=MODE;
        }
        dp[i][j][n]%=MODE;
        return dp[i][j][n];
        
    }*/
    
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>>dp(m+2,vector<vector<int>>(n+2,vector<int>(N+1,1)));
       for(int r=1; r<=m; r++){
           for(int c=1; c<=n; c++){
               dp[r][c][0]=0;
           }
       }
        
        for(int move=1; move<=N; move++){
            for(int r=1; r<=m; r++){
                for(int c=1; c<=n; c++){
                    dp[r][c][move]=0;
                    for(int dir=0; dir<4; dir++){
                    dp[r][c][move]+=dp[r+dx[dir]][c+dy[dir]][move-1];
                    dp[r][c][move]%=MODE;
                    } 
                }
            }
        }
       
        return dp[i+1][j+1][N];
    }
};