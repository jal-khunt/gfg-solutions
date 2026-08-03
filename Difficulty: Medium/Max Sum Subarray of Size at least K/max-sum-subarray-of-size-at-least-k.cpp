class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        long long current_sum = 0;
        
        // Calculate the sum of the first 'k' elements
        for (int i = 0; i < k; i++) {
            current_sum += arr[i];
        }
        
        long long max_sum = current_sum;
        
        // prev_prefix will track the running sum EXACTLY 'k' steps behind 'i'
        long long prev_prefix = 0;
        // min_prefix will track the smallest prefix sum we've seen so far
        long long min_prefix = 0;
        
        for (int i = k; i < n; i++) {
            // Update the prefix sum that is k steps behind
            prev_prefix += arr[i - k];
            
            // Update the minimum prefix sum seen so far
            min_prefix = min(min_prefix, prev_prefix);
            
            // Add the current element to our running sum
            current_sum += arr[i];
            
            // The maximum subarray sum ending at 'i' with length >= k is the 
            // current total sum minus the smallest prefix sum found at least 'k' steps ago.
            max_sum = max(max_sum, current_sum - min_prefix);
        }
        
        return max_sum;
    }
};