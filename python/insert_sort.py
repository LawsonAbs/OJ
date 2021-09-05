def insert_sort(nums):
    for i in range(1,len(nums)):
        key = nums[i]
        j = i - 1
        # 因为前面的序列有序，所以这里只需要一个while循环即可。从后往前遍历，直到当前的数大于前一个数时停止
        while(j >=0 and key < nums[j]): # 
            # swap 操作
            nums[j+1] = nums[j]
            nums[j] = key            
            j-=1


nums = [50,36,24,76,95,12,25]
print(id(nums))
insert_sort(nums)
print(id(nums)) # 排序后还是同一个nums
print(nums)