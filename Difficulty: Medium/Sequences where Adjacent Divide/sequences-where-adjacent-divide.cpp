class Solution {
  public:
    int count(int n, int m) {
        // code here
        int t[n+1][m+1];
        
        memset(t, 0, sizeof(t));
        
        for(int i = 1; i <= m; i++){
            t[1][i] = 1;
        }
        
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int k = 1; k <= m; k++){
                    if(j%k == 0 || k%j == 0)
                        t[i][j] += t[i-1][k];
                }
            }
        }
        
        int count = 0;
        
        for(int i = 0; i <= m; i++){
            count += t[n][i];
        }
        
        return count;
    }
};