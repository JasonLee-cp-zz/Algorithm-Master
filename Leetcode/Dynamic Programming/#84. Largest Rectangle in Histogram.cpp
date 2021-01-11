//O(n) left and right limit
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n),right(n);
        stack<int>limit;
        
        for(int i=0; i<n; i++){
            while(!limit.empty() && heights[limit.top()]>=heights[i]) limit.pop();
            left[i] = limit.empty() ? 0 : limit.top()+1;
            limit.push(i);
        }
        
        while(!limit.empty()) limit.pop();
        
        for(int i=n-1; i>=0; i--){
            while(!limit.empty() && heights[limit.top()]>=heights[i]) limit.pop();
            right[i] = limit.empty() ? n-1 : limit.top()-1;
            limit.push(i);
        }
        
        int max_area=INT_MIN;
        
        for(int i=0; i<n; i++){
            max_area = max(max_area,(right[i]-left[i]+1)*heights[i]);
        }
        
        return max_area;
        
    }
};

//O(n) solution one way
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n==0) return 0;
        if(n==1) return heights[0];
        heights.push_back(0); n++;
        stack<int>index;
        int i=0, h,j, max_area=0;
        while(i<n){
            if(index.empty() || heights[i] >= heights[index.top()]) index.push(i++);
            else{
                h = heights[index.top()];
                index.pop();
                j = index.empty() ? -1 : index.top();
                max_area = max(max_area,h*(i-j-1));
            }
        }
        
        return max_area;
    }
};