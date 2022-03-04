'''
这题怎么做呢？主要思路有如下两种：
（1）使用两重for循环，找出当前值依靠的最大值，其逻辑是 profit[i] = max(profit[i],profit[j]+max(0,prices[i]- prices[j]))
但这是一个二重循环，就导致很高的复杂度。所以怎么搞一个O(n) 的循环来解决这个问题？
（2） 这道题最好用一个折线图来模拟一下。如果想赚到所有的钱，就是要赚取所有的上升波段，避过所有的下降波段。
'''
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        for i in range(1,len(prices)):
            if prices[i] > prices[i-1]:
                max_profit += (prices[i]- prices[i-1])
        return max_profit

    # 下面是用两重for循环来解决这个问题
    def maxProfit_2(self, prices: List[int]) -> int:
        profit = [0] * 1e5
        res = 0
        for  i in range(len(prices)):
            for j in range(i):
                profit[i] = max(profit[i],prices[i]-prices[j])
            res = max(profit[i],res)
        return res