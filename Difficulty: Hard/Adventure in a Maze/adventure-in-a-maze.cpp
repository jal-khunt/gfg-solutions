class Solution {
  public:
    int n;
    vector<int> findWays(vector<vector<int>>& grid) {
        n = grid.size();
        
        int MOD = 1e9+7;
        
        vector<vector<int>> t(n, vector<int>(n,-1));
        vector<vector<int>> ways(n, vector<int>(n,0));
        
        t[0][0] = grid[0][0];
        ways[0][0] = 1;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(ways[i][j] == 0) continue;
                
                int val = grid[i][j];
                
                if((val == 1 || val == 3) && j+1 < n){
                    t[i][j+1] = max(t[i][j+1], grid[i][j+1] + t[i][j]);
                    ways[i][j+1] = (0LL + ways[i][j+1]+ways[i][j])%MOD;
                }
                
                if((val == 2 || val == 3) && i+1 < n){
                    t[i+1][j] = max(t[i+1][j], grid[i+1][j] + t[i][j]);
                    ways[i+1][j] = (0LL + ways[i+1][j]+ways[i][j])%MOD;
                }
            }
        }
        
        if(t[n-1][n-1] == -1)  
            t[n-1][n-1] = 0;
            
        return {ways[n-1][n-1], t[n-1][n-1]};
    }
};