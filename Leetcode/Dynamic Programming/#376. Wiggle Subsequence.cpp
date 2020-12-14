//O(n)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int>increase(n,1);
        vector<int>decrease(n,1);
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                increase[i]=decrease[i-1]+1;
                decrease[i]=decrease[i-1];
            }
            else if(nums[i]<nums[i-1]){
                decrease[i]=increase[i-1]+1;
                increase[i]=increase[i-1];
            }
            else{
                increase[i]=increase[i-1];
                decrease[i]=decrease[i-1];
            }
        }
        
        
        return max(increase[n-1],decrease[n-1]);
    }
};


//O(n^2) approach
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int>increase(n,1);
        vector<int>decrease(n,1);
        int max_len = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j]) increase[i]=max(increase[i],decrease[j]+1);
                if(nums[i]<nums[j]) decrease[i]=max(decrease[i],increase[j]+1);
                 max_len = max({max_len,increase[i],decrease[i]});
            }
        }
        
        return max_len;
    }
};


    
 