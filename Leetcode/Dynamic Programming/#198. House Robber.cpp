lass Solution {
public:
    int dp[101]{};
    vector<int>stash;
    int topdown(int n){
        if(n==0) return stash[0];
        if(n<0) return 0;
        if(dp[n]) return dp[n];
        dp[n]=max(topdown(n-1),stash[n]+topdown(n-2));
        return dp[n];
    }
    int rob(vector<int>& nums) {
        stash = nums;
        if(nums.size()==0) return 0;
        if(*max_element(nums.begin(),nums.end())==0) return 0;
        return topdown(nums.size()-1);
        
    }
};