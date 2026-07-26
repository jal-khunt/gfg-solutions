class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        vector<vector<int>> ans;
        
        int n = arr.size();
        
        int i = 1;
        
        priority_queue< int, vector<int>, greater<int> > pq;
        
        // pq.push(arr[0]);
        ans.push_back({arr[0]});
        
        while(i < n){
            int j = i * 2;
            for(; i <= j && i < n; i++){
                pq.push(arr[i]);
                // cout << arr[i] << endl;
            }
            
            vector<int> tmp;
            while(!pq.empty()){
                tmp.push_back(pq.top());
                pq.pop();
            }
            
            ans.push_back(tmp);
        }
        
        return ans;
    }
};
