class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int longest=1;
        vector<int>max_len(n,1);
        vector<int>max_num(n,1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int local_max=1;
                if(nums[i]>nums[j]){
                    if(max_len[j]+1>max_len[i]){
                        longest=max(longest,max_len[j]+1);
                        max_num[i]=max_num[j];
                        max_len[i]=max_len[j]+1;
                    }
                    else if(max_len[j]+1==max_len[i]){
                        max_num[i]+=max_num[j];
                    }
                }
            }
        }
        int res=0;
        for(int i=0; i<n; i++){
            if(max_len[i]==longest){
                res+=max_num[i];
            }
        }
        return res;
        
    }
};