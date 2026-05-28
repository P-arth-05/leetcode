from typing import List

class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # Initialize dp array with 0s, size is amount + 1
        dp = [0] * (amount + 1)
        
        # Base case: 1 way to make amount 0 (use no coins)
        dp[0] = 1
        
        # Iterate over each coin
        for coin in coins:
            # Update the dp array for all amounts that are >= current coin
            for j in range(coin, amount + 1):
                dp[j] += dp[j - coin]
                
        # The last element contains the number of combinations for the target amount
        return dp[amount]