//O(n^2) - O(2n^2) => using largest Rectangle on histogram
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0) return 0;
        int m = matrix[0].size();
        int max_area=0;
        
        vector<int>heights(m,0);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='0') heights[j]=0;
                else heights[j]++;
            }
            max_area = max(max_area,largestRectangleArea(heights,m));
        }
        
        return max_area;
    }
    
    
    int largestRectangleArea(vector<int>&heights, int n){
        if(n==1) return heights[0];
        heights.push_back(0); n++;
        stack<int>stk;
        int i=0,h,j,max_area=0;
        while(i<n){
            if(stk.empty() || heights[i] >= heights[stk.top()]) stk.push(i++);
            else{
                h = heights[stk.top()];
                stk.pop();
                j = stk.empty() ? -1 : stk.top();
                max_area = max(max_area,h*(i-j-1));
            }
        }
        return max_area;
    }
};
//O(n^3)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0) return 0;
        int m = matrix[0].size();
        vector<vector<int>>left(n,vector<int>(m,0)), up(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(j==0) left[i][j] = matrix[i][j]-'0';
                else left[i][j] = matrix[i][j]=='0'?0:left[i][j-1]+1;
                if(i==0) up[i][j] = matrix[i][j]-'0';
                else up[i][j] = matrix[i][j]=='0'?0:up[i-1][j]+1;
            }
        }
        
        int max_area=INT_MIN, cnt, min_width;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cnt=1, min_width=INT_MAX;
                for(int k=0; k<up[i][j]; k++){
                    min_width = min(min_width,left[i-k][j]);
                    max_area = max(max_area,min_width * cnt++);
                }
            }
        }
        
        return max_area==INT_MIN ? 0 : max_area;
    }
};