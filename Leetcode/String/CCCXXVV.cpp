int solve(string numeral) {
    unordered_map<char,int>mp = {{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
    int sum = 0;
    for(int i=0; i<numeral.length(); i++){
        sum += mp[numeral[i]];
        if(i==0) continue;
        if(mp[numeral[i]]>mp[numeral[i-1]]) sum -= 2*mp[numeral[i-1]]; 
    }
    return sum;
}