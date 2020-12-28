//Improved DFS
class Solution {
private:
    unordered_map<int,int>traffic[7] = {{},{{3,3},{2,2}},{{1,1},{0,0}},{{3,1},{0,2}},{{0,3},{2,1}},
                                        {{3,0},{1,2}},{{1,3},{2,0}}};
    vector<pair<int,int>>guide = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    int n,m;
    vector<vector<int>>visit;
    vector<vector<int>>grid;
    bool dfs(int dir, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        if(!traffic[grid[i][j]].count(dir)) return false;
        if(i==n-1 && j==m-1) return true;
        if(visit[i][j]) return false;
        visit[i][j]=true;
       
        int new_dir = traffic[grid[i][j]][dir];
        bool res = false;
        res = res || dfs(new_dir,i+guide[new_dir].first,j+guide[new_dir].second);
        visit[i][j]=false; 
        return res;
    }
    bool hasValidPath(vector<vector<int>>& g) {
        grid=g;
        n=grid.size(), m=grid[0].size();
        visit.resize(n,vector<int>(m,false));
        return dfs(0,0,0) || dfs(1,0,0) || dfs(2,0,0) || dfs(3,0,0);
    }
};

//My Solution
class Solution {
private:
    unordered_map<int,pair<int,int>>traffic = {
        {0,{-1,0}}, {1,{1,0}}, {2,{0,-1}}, {3,{0,1}}
    };
    unordered_map<int,vector<int>>pathway={
        {1,{0,0,1,1}}, {2,{1,1,0,0}}, {3,{0,1,1,0}}, {4,{0,1,0,1}}, {5,{1,0,1,0}}, {6,{1,0,0,1}}
    };
    
public:
    vector<vector<int>>visited;
    int n,m;
    bool dfs(vector<vector<vector<int>>>&board, int dir, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        int new_dir = dir&1 ? dir-1: dir +1;
        if(i!=0 || j!=0)
             if(!board[i][j][new_dir] || visited[i][j]) return false;
        if(i==n-1 && j==m-1) return true;
        visited[i][j] = true;
        
        bool res = false;
        for(int d=0; d<4; d++){
           if(i==n-1 && j==m-1) {if(d==new_dir) continue;}
            if(board[i][j][d]){
                res = res || dfs(board,d,i+traffic[d].first, j+traffic[d].second);
            }
        }
        visited[i][j]=false;
        return res;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        visited.resize(n,vector<int>(m,false));
        vector<vector<vector<int>>>board(n,vector<vector<int>>(m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                board[i][j]=pathway[grid[i][j]];
        
        return dfs(board,0,0,0);
    }
};