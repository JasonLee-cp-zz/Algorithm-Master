//Bottom Up
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if(target & 1) return false; //if odd -> then it's impossible
        target/=2;
        
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,false));
        
        //dp[][0]=true; -> we can always fill 0 weight by not putting any item
        for(int i=0; i<=n; i++)
            dp[i][0]=true;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){
                if(nums[i-1]>j) dp[i][j]=dp[i-1][j];
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
        }
        
        return dp[n][target];
    }
};

//TopDown (2^n)
class Solution {
public:
    vector<vector<int>>dp;
  
    bool topdown(vector<int>&nums, int target, int i){
        if(target<0 || i<0) return false;
        if(target==0) return true;
        if(dp[i][target]!=-1) return dp[i][target];
        
        if(nums[i]>target) dp[i][target]=topdown(nums,target,i-1);
        else{
            dp[i][target]=topdown(nums,target-nums[i],i-1) || topdown(nums,target,i-1);
        }
     
        return dp[i][target];
        
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if(total_sum%2!=0) return false;
        total_sum/=2; //this is our target
         dp.clear();
         dp.resize(n,vector<int>(total_sum+1,-1));
        return topdown(nums,total_sum,n-1);
    }
};