"""
使用python相关特性完成
"""
class Solution:
    # 删除重复一个数组中的重复元素
    # 输入一个数组，返回值是删除重复数组之后的长度    
    def removeDuplicates(self,nums) -> int:
        for i in range(len(nums) - 1, 1, -1):
            if nums[i] == nums[i - 1]: #  如果i 为0，则（i-1）变成了 -1，但是 -1 并非越界，而是最后一项
                del nums[i] # 删除的永远都是
        # print(nums)
        return len(nums)


if __name__ == "__main__":
    nums = [0,0,1,1,1,2,2,3,3,4]
    # nums = [0,1]
    nums = [0,1,2,3]
    solution = Solution()
    ans = solution.removeDuplicates(nums)
    print(ans)