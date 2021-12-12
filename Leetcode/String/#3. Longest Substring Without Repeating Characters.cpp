
// 1. Extreme Optimizatio - Beats 100%
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = -1, max_len = 0;
        vector<int>pos(256,-1);
        
        for(int i=0; i<s.length(); i++){
           if(pos[s[i]] >= start) start = pos[s[i]] + 1;
           pos[s[i]] = i; 
            max_len = max(max_len, i-start+1);
        }
        
        return max_len;
    }
};

// 2. Optimized  using character vector 256
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int start = 0, max_len = 0, cur_len = 0;
        vector<int>alphabets(256,0);
        
        for(int i=0; i<n; i++){
           while(alphabets[s[i]] > 0){
               alphabets[s[start++]] = 0;
               cur_len--;
           }
            
            alphabets[s[i]]++;
            cur_len++;
    
            if(cur_len > max_len) max_len = cur_len;
        }
        
        return max_len;
    }
};

// 3. Sliding Window using unordered_set
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int start = 0, max_len = 0;
        string cur = "";
        unordered_set<char>box;
        
        for(int i=0; i<n; i++){
            while(cur.find(s[i]) != string::npos)
                cur = cur.substr(1);
            
            cur += s[i];
    
            if(static_cast<int>(cur.length()) > max_len)
                max_len = cur.length();
        }
        
        return max_len;
    }
};