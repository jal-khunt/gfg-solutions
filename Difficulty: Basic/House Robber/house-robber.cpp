class Solution {
  public:
    int maximizeMoney(int n, int k) {
        // code here
        if(n%2){
            return ((n/2) + 1) * k;
        }
        
        return (n/2) * k;
    }
};