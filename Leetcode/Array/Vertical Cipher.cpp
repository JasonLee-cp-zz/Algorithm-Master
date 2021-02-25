vector<string> solve(string s, int k) {
    int n = s.length();
    vector<string>res(k,"");
    for(int i=0; i<n; i++){
        res[i%k].push_back(s[i]);
    }
    return res;
}