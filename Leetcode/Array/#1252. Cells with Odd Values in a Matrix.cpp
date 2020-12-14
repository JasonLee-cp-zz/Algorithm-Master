class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        unordered_map<int,int>row;
        unordered_map<int,int>col;
        for(auto i: indices){
            row[i[0]]++;
            col[i[1]]++;
        }
        
        vector<vector<int>>matrix(n,vector<int>(m,0));
        for(auto r: row){
            for(int i=0; i<m; i++){
                matrix[r.first][i]+=r.second;
            }
        }
        for(auto c: col){
            for(int i=0; i<n; i++){
                matrix[i][c.first]+=c.second;
            }
        }
        
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]%2==1) cnt++;
            }
        }
        return cnt;
        
        
        
    }
};