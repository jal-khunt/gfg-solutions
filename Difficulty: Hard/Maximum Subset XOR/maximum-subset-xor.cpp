class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        // code here
        // basis[i] will store a number whose highest set bit is at the i-th position
        vector<int> basis(32, 0);
        
        // Step 1: Build the Linear Basis
        for (int x : arr) {
            for (int i = 31; i >= 0; i--) {
                // If the i-th bit of x is set
                if ((x >> i) & 1) {
                    // If the basis for this bit is empty, x becomes the basis
                    if (!basis[i]) {
                        basis[i] = x;
                        break;
                    }
                    // Otherwise, XOR x with the basis to eliminate this bit and continue
                    x ^= basis[i];
                }
            }
        }
        
        // Step 2: Find the Maximum XOR
        int max_xor = 0;
        for (int i = 31; i >= 0; i--) {
            // Greedily take the basis number if it increases our current XOR
            if ((max_xor ^ basis[i]) > max_xor) {
                max_xor ^= basis[i];
            }
        }
        
        return max_xor;
    }
};