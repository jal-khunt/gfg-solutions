class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if(n == 1) return 0;
        
        int a = 0, b = abs(height[0] - height[1]);
        
        for(int i = 2; i < n; i++){
            int one_step = abs(height[i] - height[i-1]) + b;
            int two_step = abs(height[i] - height[i-2]) + a;
            
            a = b;
            b = min(one_step, two_step);
        }
        
        return b;
    }
};