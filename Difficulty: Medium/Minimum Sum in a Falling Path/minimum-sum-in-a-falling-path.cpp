class Solution {
  public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        // code here
        int r = mat.size(), c = mat[0].size();
        
        vector<vector<int>> t(r,vector<int> (c,INT_MAX));
        for(int i = 0; i < c; i++){
            t[0][i] = mat[0][i];
        }
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                // cout <<" " << i << j << " :";
                if(i+1 < r){
                    t[i+1][j] = min(t[i+1][j], t[i][j] + mat[i+1][j]);
                    // cout << t[i+1][j];
                    if(j+1 <c){
                        t[i+1][j+1] = min(t[i+1][j+1], t[i][j] + mat[i+1][j+1]);
                        // cout << " " << t[i+1][j+1];
                    }
                    if(j-1 >= 0){
                        t[i+1][j-1] = min(t[i+1][j-1], t[i][j] + mat[i+1][j-1]);
                        // cout << " " << t[i+1][j-1];
                    }
                }
            }
            // cout << endl;
        }
        
        int ans = INT_MAX;
        
        // for(int i = 0; i < r; i++){
        //     for(int j = 0; j < r; j++){
        //     cout << t[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        for(int i = 0; i < c; i++){
            ans = min(ans, t[c-1][i]);
        }
        
        return ans;
    }
};
