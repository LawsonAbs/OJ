'''快速排序
01.quick_sort 是一个入口函数
02.真正的排序部分放到了partition中，使用partition将一个list分成左右两个部分，并且返回分割点的index
'''
# 快排中的分区函数
def quick_sort(left,right,nums):
    if left >= right:
        return 
    mid = partition(left,right,nums)
    quick_sort(left,mid-1,nums)
    quick_sort(mid+1,right,nums)


# 将区间 [left,right] 排序
def partition(left,right,nums):
    pivot_key = nums[left] # 取为数轴值
    while(left < right): # 满足此条件就一直循环
        while(left < right and nums[right] >= pivot_key):
            right -= 1
        nums[left] = nums[right]

        while(left < right and nums[left] <= pivot_key):
            left += 1
        nums[right] = nums[left]
        
    nums[left] = pivot_key
    return left


nums = [50,36,24,76,95,12,25]
quick_sort(0,6,nums)
print(nums)