# 从小到大，冒泡排序
def bubble_sort(nums):
    # 这里的i表示的当前已经排好的轮数，每轮排好，都有一个数排好，所以也可以认为是已经排好序的个数
    for i in range(0,len(nums)):
        # 因为从小到大排序，所以排过的序列的是有序的（也就是），所以tail = len(nums) - i
        # 冒泡排序必须是从第一个元素开始比较交换，即j的开始值是0
        for j in range(1,len(nums)-i): 
            k = j-1 # nums[k] 是前一个数
            temp = nums[k]
            if nums[k] > nums[j]:
                nums[k] = nums[j]
                nums[j] = temp
        # print(nums)
        #         
nums = [50,36,24,76,95,12,25]
bubble_sort(nums)
print(nums)