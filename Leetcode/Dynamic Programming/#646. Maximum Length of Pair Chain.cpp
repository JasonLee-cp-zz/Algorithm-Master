class Solution {
    private:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0]<b[0]) return true;
        else if(a[0]==b[0]) return a[1]<b[1];
        else return false;
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int>dp1(n,1);
        int max_len = 1;
        sort(pairs.begin(),pairs.end(),cmp);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(pairs[i][0]>pairs[j][1]){
                    dp1[i]=max(dp1[i],1+dp1[j]);
                    max_len=max(max_len,dp1[i]);
                }
            }
        }
       
        return max_len;
    }
};