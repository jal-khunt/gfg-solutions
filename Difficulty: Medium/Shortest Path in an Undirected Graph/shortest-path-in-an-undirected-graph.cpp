class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // Code here
        vector<vector<pair<int,int>>> adj(V+1);
        
        for(auto& e : edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> dist(V+1, INT_MAX);
        
        dist[dest] = 0;
        pq.push({0,dest});
        
        while(!pq.empty()){
            auto [d, n] = pq.top();
            pq.pop();
            
            if(d > dist[n]) continue;
            
            for(auto &p : adj[n]){
                int wt = p.second, v = p.first;
                
                if(d + wt < dist[v]){
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        
        
        if(dist[src] == INT_MAX){
            return {-1};
        }
        
        vector<int> path;
        int curr = src;
        path.push_back(curr);
        
        while(curr != dest){
            int next = -1;
            
            for(auto &p : adj[curr]){
                int v = p.first, wt = p.second;
                
                if(wt + dist[v] == dist[curr]){
                    if(next == -1 || v < next){
                        next = v;
                    }
                }
            }
            
            curr = next;
            path.push_back(curr);
        }
        
        return path;
    }
};