class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        
        vector< vector< pair<int,int> >> adj(V);
        
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v,wt} );
            adj[v].push_back( {u, wt} );
        }
        
        // priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        set<pair<int,int>> st;
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        // pq.push( {0, src} );
        st.insert({0, src});
        
        while(!st.empty()){
            // auto it = pq.top();
            auto it = *(st.begin());
            int n = it.second;
            int d = it.first;
            // pq.pop();
            st.erase(it);
            
            for(auto &p : adj[n]){
                int adjNode = p.first, wt = p.second;
                
                if(d + wt < dist[adjNode]){
                    if(dist[adjNode] != INT_MAX){
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = d + wt;
                    // pq.push({dist[adjNode], adjNode});
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};