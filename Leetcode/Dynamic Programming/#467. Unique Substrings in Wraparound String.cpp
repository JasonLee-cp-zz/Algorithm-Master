class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int>cnt(26,0);
        int mx=1;
        for(int i=0; i<p.length(); i++){
            if(i>0 &&  (p[i]-p[i-1]==1 || p[i]-p[i-1]==-25)){
                mx++;
            }
            else{
                mx=1;
            }
            cnt[p[i]-'a'] = max(cnt[p[i]-'a'],mx);
        }
        int res=0;
        for(auto i: cnt)
            res+=i;
        return res;
    }
};