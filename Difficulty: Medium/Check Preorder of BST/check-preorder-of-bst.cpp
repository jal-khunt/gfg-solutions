class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        stack<int> st;
        int min_limit = INT_MIN;
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top() < arr[i]){
                min_limit = st.top();
                st.pop();
            }
            
            if(arr[i] <= min_limit){
                return false;
            }
            
            st.push(arr[i]);
        }
        
        return true;
    }
};