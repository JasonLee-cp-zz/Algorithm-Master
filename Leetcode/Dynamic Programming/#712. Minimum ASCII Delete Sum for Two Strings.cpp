//bottom up
class Solution {
public:
   
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        dp[0][0]=0;
        for(int i=1; i<=n1; i++)
            dp[i][0]=s1[i-1]+dp[i-1][0];
        for(int j=1; j<=n2; j++)
            dp[0][j]=s2[j-1]+dp[0][j-1];
        
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(s1[i-1]+dp[i-1][j],s2[j-1]+dp[i][j-1]);
            }
        }
        return dp[n1][n2];
        
        
    }
};

//top down
class Solution {
public:
    vector<vector<int>>dp;
    int helper(int t, string &s){
        int sum=0;
        for(int i=0; i<=t; i++){
            sum+=(int)s[i];
        }
        return sum;
    }
    int minSum(int i, int j,string &s, string &t){
         if(i==-1 && j==-1) return 0;
         if(i==-1 && j>=0) return helper(j,t);
         if(i>=0 && j==-1) return helper(i,s);
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=minSum(i-1,j-1,s,t);
        else return dp[i][j]=min((int)t[j]+minSum(i,j-1,s,t),(int)s[i]+minSum(i-1,j,s,t));
    }
    int minimumDeleteSum(string s1, string s2) {
        int n1 =s1.length();
        int n2 = s2.length();
        dp.resize(n1,vector<int>(n2,-1));
        return minSum(n1-1,n2-1,s1,s2);
        
        
    }
};