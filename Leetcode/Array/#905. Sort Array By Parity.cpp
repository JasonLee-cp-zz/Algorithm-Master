class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        vector<int>res(n);
        int i=0, j=n-1;
        for(auto itr: A){
            if(itr%2==0) res[i++]=itr;
            else res[j--]=itr;
        }
        return res;
    }
};