class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>>res;
        int cnt=1; int n = s.length();
        for(int i=0; i<n; i++){
            if(i<n-1 && s[i]==s[i+1]){
                cnt++;
            }else{
                if(cnt>=3) res.push_back({i-cnt+1,i});
                cnt=1;
            }
        }
        return res;
    }
};