class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int n = arr.size();
        long long best = LLONG_MAX;

        // Enumerate all non-empty subsets using bitmask
        for (int mask = 1; mask < (1 << n); mask++) {
            long long product = 1;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    product *= arr[i];
                }
            }
            best = min(best, product);
        }

        return best;
    }
};