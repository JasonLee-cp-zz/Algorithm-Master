class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int>sold(n,0);
        vector<int>hold(n,0);
        hold[0]= -1*prices[0];
        for(int i=1; i<n; i++){
            sold[i]=max(sold[i-1],hold[i-1]+prices[i]-fee);
            hold[i]=max(sold[i-1]-prices[i],hold[i-1]);
        }
        return sold[n-1];
    }
};