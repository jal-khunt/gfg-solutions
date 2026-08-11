class Solution {
  public:
    int unvisitedLeaves(vector<int>& arr, int k) {
        // code here
        vector<bool> vis(k+1, false);
        
        sort(arr.begin(), arr.end());
        
        if(arr[0] == 1) return 0;
        
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(arr[i] <= k && vis[arr[i]]) continue;
            for(int j = arr[i]; j <= k; j+=arr[i]){
                vis[j] = true;
            }
        }
        
        int count = 0;
        for(auto i : vis){
            if(!i) count++;
        }
        return count-1;
    }
};