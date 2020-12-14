class Solution {
public:
    vector<vector<double>>dp;
    double topdown(int i, int k, vector<double>&prefix, int n){
        if(k==1) return (prefix[n-1]-prefix[i-1])/((n-1)-i+1);
        if(dp[i][k]!=-1) return dp[i][k];
        double sum=0;
        for(int j=i+1; j<=n-1; j++)
            sum=max(sum,(prefix[j-1]-prefix[i-1])/(j-1-i+1)+topdown(j,k-1,prefix,n));
        
        sum=max(sum,(prefix[n-1]-prefix[i-1])/(n-1-i+1));
        return dp[i][k]=sum;
    }
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<double>prefix(n+1,0);
        dp.resize(n+1,vector<double>(K+1,-1));
        for(int i=1; i<n+1; i++)
            prefix[i]=A[i-1]+prefix[i-1];
        if(K==1) return prefix[n]/n;
        if(K>=n) return prefix[n];
        return topdown(1,K,prefix,n+1);
        
        
    }
};