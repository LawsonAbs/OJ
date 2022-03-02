"""
使用双指针
"""
class Solution:
    # 删除重复一个数组中的重复元素
    # 输入一个数组，返回值是删除重复数组之后的长度    
    def removeDuplicates(self,nums) -> int:
        i = 0 # 赋初始值
        j = 1
        while j < len(nums) : # 总条件
            while (j < len(nums) and nums[j] == nums[i] ):
                j+=1
            
            # 可能经过上面这个while，j的值已经不符合条件了。所以需要一个if 判断是否满足赋值条件
            if j< len(nums): 
                i+=1
                nums[i] = nums[j]
            else:  # 如果不满足，则说明整个数组都遍历过，直接跳出
                break
        return i+1 # 因为从0开始计数

if __name__ == "__main__":
    nums = [0,0,1,1,1,2,2,3,3,4]
    # nums = [0,1]
    nums = [0,1,2,3]
    solution = Solution()
    ans = solution.removeDuplicates(nums)
    print(ans)