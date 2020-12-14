class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(S>sum) return 0;
        vector<vector<int>>dp(nums.size()+1,vector<int>(2*sum+1,0));
        dp[0][sum]=1;
        
        for(int i=1; i<=nums.size(); i++){
            for(int j=0; j<2*sum+1; j++){
                int prev = dp[i-1][j];
                if(prev!=0){
                    dp[i][j+nums[i-1]]+=prev;
                    dp[i][j-nums[i-1]]+=prev;
                }
            }
        }
        
        return dp[nums.size()][sum+S];
    }
};