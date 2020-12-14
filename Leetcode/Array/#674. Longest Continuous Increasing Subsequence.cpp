class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int cnt=1;
        int max_len=1;
        for(int i=1; i<nums.size(); i++){
            nums[i]>nums[i-1]?cnt++:cnt=1;
             max_len=max(max_len,cnt);
        }
        return max_len;
    }
};