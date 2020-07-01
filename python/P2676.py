#使用python 搞一遍快排
def quickSort(left,right):
    if left >= right:
        return
    tl = left
    tr = right
    pivot = nums[left]
    while tl < tr:
        while tl < tr and nums[tr] >= pivot: # 先从右边开始
            tr -= 1
        nums[tl] = nums[tr] # 赋值

        while tl < tr and nums[tl] <= pivot: # 再从左边枚举
            tl += 1
        nums[tr] = nums[tl]

    nums[tr] = pivot # 更新分界点
    quickSort(left,tr-1)
    quickSort(tr+1,right)

s = input()
n = int(s.split(" ")[0])
B = int(s.split(" ")[1])


nums = []
for i in range(int(n)):
    num = input()
    nums.append(int(num))

quickSort(0,len(nums)-1) # 快排

#
sum = 0
cnt = 0
for i in nums[::-1]:
    sum+=i
    cnt += 1
    if sum >= B:
        print(cnt)
        break
#

"""
23 3 4 12 1
23 3 12 3 1
"""