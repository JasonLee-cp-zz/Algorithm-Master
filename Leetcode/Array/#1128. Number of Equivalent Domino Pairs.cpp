class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
         unordered_map<int,int>mp;
        int cnt=0;
        for(auto i: dominoes){
            int n = min(i[0],i[1])*10+max(i[0],i[1]);
           cnt+=mp[n]++;
        }
         
        return cnt;
    }
};