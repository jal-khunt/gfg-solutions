class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        vector<bool> vis(V, false);
        
        int sum = 0;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            auto [wt, node] = pq.top();
            pq.pop();
            
            if(vis[node]) continue;
            
            vis[node] = true;
            
            sum += wt;
            
            for(auto &[v, w] : adj[node]){
                pq.push({w, v});
            }
        }
        
        return sum;
    }
};