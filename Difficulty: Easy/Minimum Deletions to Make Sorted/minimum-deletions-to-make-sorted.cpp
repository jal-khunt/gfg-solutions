class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n <= 1) return 0;
        
        vector<int> seq;
        
        for(int i = 0; i < n; i++){
            auto it = lower_bound(seq.begin(), seq.end(), arr[i]);
            
            if(it == seq.end()){
                seq.push_back(arr[i]);
            }
            else{
                *it = arr[i];
            }
        }
        
        return n - seq.size();
    }
};