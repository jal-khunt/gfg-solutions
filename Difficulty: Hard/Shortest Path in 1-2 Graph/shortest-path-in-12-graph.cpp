class Solution {
  public:
    int shortestPath(int V, int src, int dst, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &edge : edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        vector<int> dest(V, INT_MAX);
        dest[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            
            if(d > dest[u]) continue;
            
            for(auto &p : adj[u]){
                auto [v, wt] = p;
                
                if(d + wt < dest[v]){
                    dest[v] = d + wt;
                    pq.push({dest[v], v});
                }
            }
        }
        
        return dest[dst] == INT_MAX ? -1 : dest[dst];
    }
};