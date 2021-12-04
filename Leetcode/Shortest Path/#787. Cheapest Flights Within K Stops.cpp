// DFS
// BFS
// Dijkstra
// DP
// Bellman Ford

// DFS
class Solution {
public:
    int res = INT_MAX;
    int dest;
    vector<int>visited;
    void dfs(vector<vector<pair<int,int>>>&adj, int k, int cost, int cur){
        if(visited[cur]) return;
        visited[cur] = true;
        
        if(cur == dest){
            res = min(res, cost);
            visited[cur] = false;
            return;
        }
        
        if(k <= 0){
            visited[cur] = false;
            return;
        }
        
        for(auto &p: adj[cur]){
            if(cost+p.second >= res) continue;
            dfs(adj,k-1,cost+p.second,p.first);
        }
        
        visited[cur] = false;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        dest = dst;
        vector<vector<pair<int,int>>>adj(n);
        visited.resize(n, false);
        for(auto &flight: flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        
        dfs(adj,k+1,0,src);
        
        return res == INT_MAX ? -1 : res;
        
        
        
    }
};

// Dijkstra - Priority Queue
class Solution {
public:
    int dest;
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // Data Structures
        vector<vector<pair<int,int>>>adj(n);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        
        // Initialization
        pq.push({0, src, k+1}); // pair<weight, node>
        int res = INT_MAX; // cheapest price for dst
        
        
        for(auto &f: flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        
        // Dijkstra with Priority Queue
        while(!pq.empty()){ 
            auto cur = pq.top(); pq.pop(); // pair<weight, node>
            int curCost = cur[0];
            int minNode = cur[1];
            int remainingStops = cur[2];
            
            
            if(minNode == dst) res = min(res, curCost);
            if(remainingStops <= 0) continue; // At most "K"
            
            for(auto &v: adj[minNode]){ // Dont' update dist[] -> we don't even have that!
                // Since we have "K" restraints, even if a cost at a certain vertex is "lower" than another route,
                // That path might just not have ZERO "K" left -> so path with more cost can be the answer!
                /// This is why we don't have & update the dist[] array
                
                // We also don't need visited array either -> we're using priority queue!
                pq.push({curCost + v.second, v.first, remainingStops - 1});
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }
};
