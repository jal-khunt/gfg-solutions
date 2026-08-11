class Solution {
  public:
    int t[100001];
    int solve(int i, int n, vector<int>& arr){
        if(i > n)
            return 0;
            
        if(t[i] != -1)
            return t[i];
            
        int include = arr[i] + solve(i+2, n, arr);
        int notInclude = solve(i+1, n, arr);
        
        return t[i] = max(include, notInclude);
    }
  
  
    int maxValue(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        if(n == 1)  return arr[0];
        if(n == 2) return max(arr[0], arr[1]);
        
        memset(t, -1, sizeof(t));
        
        int take0 = solve(0, n-2, arr);
        
        memset(t, -1, sizeof(t));
        
        int take1 = solve(1, n-1, arr);
        
        return max(take0, take1);
    }
};
