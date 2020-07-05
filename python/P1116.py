"""
用归并排序求逆序数
本题主要有如下几个点需要注意：
01.归并排序用Python的写法
02.python 中数组如果没有申请足够大小是无法直接通过下标访问的
03.样例输入输出的问题。本题的测试样例采取了三种 不同的输入方式：
 a.以空格分割
 b.以换行分割
 c.以空格和换行分割
反正输入的数据特别烦人，令我恼羞成怒！
"""
N = 10005
res = 0
temp = [0] * N # 临时数组，必须使用这种方式才可以，如果直接用.append()的话，会出现问题
# 使用归并排序
def mergeSort(left,right):
    global res
    global temp
    if left >= right: # 直接返回
        return
    mid = (left+right)//2  # 直接二分
    mergeSort(left,mid)
    mergeSort(mid+1,right)

    # 开始合并
    index = tl = left
    tr = mid + 1
    while tl <= mid and tr <= right:
        if arr[tl] <= arr[tr]:
            temp[index] = arr[tl] # 开始赋值
            tl += 1
            index += 1

        # 如果是从右侧开始赋值，说明左侧的值要大
        if arr[tr] <= arr[tl]:
            temp[index] = arr[tr]  # 开始赋值
            tr+=1
            index+=1
            res += (mid - tl + 1)

    # 赋值剩余的数组值
    while tl<=mid:
        temp[index]=arr[tl]
        tl+=1
        index+=1

    while tr<=right:
        temp[index] = arr[tr]
        index+=1
        tr+=1
        res += (mid-tl+1)

    # 写回到arr 数组中
    for i in range(left,right+1):
        arr[i] = temp[i]


n = input()
n = int(n)
arr=[]
while len(arr)<n: # 如果没有读够n个数字
    num = input()
    nums = num.strip().split()
    nums = [int(i) for i in nums]
    for i in nums:
        arr.append(i)
#print(arr)

# 进行一个归并排序
mergeSort(0,n-1)
# for i in range(n):
#     print(arr[i],end = " ")
print(res)

"""
5
1 4 2 5 3 

5
1
2
3
4
5
"""