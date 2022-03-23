from typing import List

INT_MAX = 2<<30
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [INT_MAX] * (amount + 1) # 表示到i需要最少的硬币数，初始化均为-1
        dp[0] = 0
        for i in range(0,amount+1): # 对每个amount 进行评估
            for j in range(len(coins)):
                if i>=coins[j]: # 如果当前的数目超过当前的零钱
                    dp[i] = min(dp[i-coins[j]]+1,dp[i])
        # print(dp)
        if dp[amount] == INT_MAX:
            return -1
        return dp[amount]
            

s = Solution()
coins = [1]
amount = 0
s.coinChange(coins,amount)