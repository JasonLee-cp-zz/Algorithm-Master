class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //two Product Variables and sort of "swap"
       if(nums.empty()) 
        return 0;
        int current_max = nums[0];
        int current_min = nums[0];
        int max_product=nums[0];
        for(int i=1; i<nums.size(); i++){
            int p1 = current_max * nums[i]; 
            int p2 = current_min * nums[i]; 
            current_max = max({p1,p2,nums[i]});   
            current_min = min({p1,p2,nums[i]}); 
            max_product = max(max_product,current_max);
        }
        return max_product;
        /*Prefix Product Array
        unordered_set<int>st;
        st.insert(1);
        int product=1;
        int max_product=INT_MIN;
        for(auto i: nums){
            if(i==0){
                st.clear();
                st.insert(1);
                product=1;
                continue;
            }
            product = product * i;
            for(auto itr: st){
                if(product/itr>0) max_product = max(max_product, product/itr);
            }
            st.insert(product);
        }
        return max_product==INT_MIN ? *max_element(nums.begin(),nums.end()) : max_product;
        */
        
    }
};