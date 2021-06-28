vector<int>dp;
int n;
vector<int> visited;

bool topdown(vector<int>&nums, int i){
    if(visited[i]) return false;
    if(nums[i]==0 && i!=n-1) return false;
    if(i<0 || i>=n) return false;
    if(i==n-1) return true;
    visited[i] = true;

    if(dp[i] != -1) return dp[i];

    dp[i] = topdown(nums, i-nums[i]) || topdown(nums, i+nums[i]); 
    visited[i] = false;
    
    return dp[i];
}

bool solve(vector<int>& nums, int k) {
    n = nums.size();
    dp.clear(); visited.clear();
    dp.resize(n,-1); visited.resize(n,false);
    return topdown(nums,k);
}
