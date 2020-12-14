//Plain DP

class Solution {
public:
    int r,c;
    #define ll long long
    #define MODE 1000000007
    vector<vector<vector<ll>>>dp;
    int dx[8]={2,1,-1,-2,-2,-1,1,2};
    int dy[8]={1,2,2,1,-1,-2,-2,-1};
    
     ll topdown(int i, int j, int k){
        if(i<0 || j<0 || i>=r || j>=c || (i==3 && j==0) || (i==3 && j==2)) return 0;
        if(k==0) return 1;
        if(dp[i][j][k]) return dp[i][j][k];
         
        int res=0;
        for(int dir=0; dir<8; dir++){
            res+=topdown(i+dx[dir],j+dy[dir],k-1);
            res%=MODE;
        }
        return dp[i][j][k]=res;
    }
    
    int knightDialer(int n) {
        r=4; c=3;
        dp.resize(r,vector<vector<ll>>(c,vector<ll>(n,0)));
        ll res=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if((i==3&&j==0) || (i==3 && j==2)) continue;
                res+=topdown(i,j,n-1);
                res%=MODE;
            }
        }
        return res;
    }
};