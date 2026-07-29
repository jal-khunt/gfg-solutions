class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        int ans = 1;
        
        for(int i = 0; i < n-1; i++){
            if(arr[i] + 1 != arr[i+1])
                ans++;
        }
        
        return ans;
    }
};
