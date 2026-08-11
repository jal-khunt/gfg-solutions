class Solution {
    int n;
    vector<int> t;
  public:
    int solve(int i, vector<int>& height){
        if(i >= n-1) return 0;
        
        if(t[i] != -1)
            return t[i];
        
        int one_step = INT_MAX, two_step = INT_MAX;
        if(i+1 < n)
            one_step = abs(height[i] - height[i+1]) + solve(i+1, height);
        if(i + 2 < n)
            two_step = abs(height[i] - height[i+2]) + solve(i+2, height);
        
        return t[i] = min(one_step, two_step);
    }
  
    int minCost(vector<int>& height) {
        // Code here
        n = height.size();
        t.resize(n+1, -1);
        
        return solve(0, height);
    }
};