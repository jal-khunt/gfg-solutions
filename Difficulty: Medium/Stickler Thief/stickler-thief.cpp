class Solution {
  public:
    int n;
    vector<int> t;
    int solve(int i, vector<int> & arr){
        if(i >= n) return 0;
        if(t[i] != -1)
            return t[i];
            
        int include = arr[i] + solve(i+2,arr);
        int notInclude = solve(i+1, arr);
        
        return t[i] = max(include, notInclude);
    }
  
    int findMaxSum(vector<int>& arr) {
        n = arr.size();
        t.resize(n+1, -1);
        return solve(0, arr);
    }
};