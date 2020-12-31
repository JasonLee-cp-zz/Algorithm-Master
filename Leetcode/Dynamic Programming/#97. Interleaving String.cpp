//Bottom Up DP - O(n^2) 4m/s
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if(n3 != n1 + n2) return false;
        
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,false));
        // dp[i][j] = whether the first i+j elements of s3 is the interleaving string of first i elements of s1 and first j elements of s2
        
        dp[0][0]=true;
        for(int i=1; i<=n1; i++)
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        
        for(int j=1; j<=n2; j++)
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1])) || (dp[i][j-1] && (s2[j-1] == s3[i+j-1]));
            }
        }
        
        return dp[n1][n2]; 
    }
};

//Topdown DP Approach 70m/s
class Solution {
public:
    vector<vector<vector<int>>>dp;
    bool topdown(string &s1, string &s2, string &s3, int i, int j, int n){
        if(n<1){
            if(i>=1 || j>=1) return false;
            return true;
        } 
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        
        if(i>=1 && j>=1 && s3[n-1]==s1[i-1] && s3[n-1]==s2[j-1]){
            return dp[i][j][n] = topdown(s1,s2,s3,i-1,j,n-1) || topdown(s1,s2,s3,i,j-1,n-1);
        }
        else if(i>=1 && s3[n-1]==s1[i-1]){
            return dp[i][j][n] = topdown(s1,s2,s3,i-1,j,n-1);
        }
        else if(j>=1 && s3[n-1]==s2[j-1]){
            return dp[i][j][n] = topdown(s1,s2,s3,i,j-1,n-1);
        }
        
        return dp[i][j][n] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        dp.resize(s1.length()+1, vector<vector<int>>(s2.length()+1,vector<int>(s3.length()+1,-1)));
        return topdown(s1,s2,s3,s1.length(),s2.length(),s3.length());
    }
};