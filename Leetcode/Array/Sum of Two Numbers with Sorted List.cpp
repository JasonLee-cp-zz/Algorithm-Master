bool solve(vector<int>& nums, int k) {
    int i=0, j=nums.size()-1, cur;
    while(i<j){
        cur = nums[i] + nums[j];
        if(cur==k) return true;
        else if(cur<k) i++;
        else j--;
    }
    return false;
}