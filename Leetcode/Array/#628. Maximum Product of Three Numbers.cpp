class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       int oneMax,oneMin,twoMax,twoMin,threeMax;
        oneMax=twoMax=threeMax=INT_MIN;
        oneMin=twoMin=INT_MAX;
        
        for(int i=0; i<nums.size(); i++){
            if(i>=2) threeMax=max({threeMax,nums[i]*twoMax,nums[i]*twoMin});
            if(i>=1)twoMax=max({twoMax,nums[i]*oneMax,nums[i]*oneMin});
            if(i>=1)twoMin=min({twoMin,nums[i]*oneMax,nums[i]*oneMin});
            oneMax=max(oneMax,nums[i]);
            oneMin=min(oneMin,nums[i]);
        }
        return threeMax;
    }
};