class Solution:
    
    def solve(self, n: int, memo) -> int:
        if n < 0:
            return 0
        if n == 0:
            return 1
            
        if memo[n] != -1:
            return memo[n]
            
        memo[n] = self.solve(n-1,memo) + self.solve(n-2,memo)
        return memo[n]
        
    def countWays(self, n: int) -> int:
        # code here
        memo = [-1] * (n+1)
        return self.solve(n,memo)
        