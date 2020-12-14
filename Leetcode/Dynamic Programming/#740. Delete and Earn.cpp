class Solution {
public:
    
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
       vector<int>bucket(n,0);
        for(int i: nums)
            bucket[i]+=i;
      
        int take=0;
        int skip=0;
        for(int i=0; i<n; i++){
            int curr_skip = max(take,skip);
            int curr_take = bucket[i]+skip;
            take=curr_take;
            skip=curr_skip;
        }
        return max(take,skip);
    }
};
/*straightfoward DP
class Solution {
public:
    unordered_map<int,int>mp;
    
    int deleteAndEarn(vector<int>& nums) {
       vector<int>bucket(10001,0);
        for(int i: nums)
            bucket[i]+=i;
        vector<int>dp(10001,0);
        dp[0]=0;
        dp[1]=bucket[1];
        for(int i=2; i<bucket.size(); i++){
            dp[i]=max(bucket[i]+dp[i-2],dp[i-1]);
        }
        return dp[10000];
        
    }
};
*/