class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        vector<int> arr(n+1,0);
        
        for(int i = 0; i < a.size(); i++){
            arr[a[i]] += k[i];
            
            arr[b[i]+1] -= k[i];
        }
        
        int current_sum = 0;
        int max_val = 0;
        
        for(int i = 0; i < n; i++){
            current_sum += arr[i];
            
            max_val = max(max_val, current_sum);
        }
        
        return max_val;
    }
};