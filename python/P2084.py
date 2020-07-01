"""
01./= 是做浮点数除法； //= 才是做整数除法
"""
#将一个M进制的数N 转换成十进制表示的式子
def transform(M,N):
    nums = [] #中间序列
    tot = -1
    # 得到数字N的每一位
    while N:
        rest = N % 10  # 余数
        N //= 10  # 并没有做整数除法
        if rest: # 计算总得输出项个数
            tot+=1
        nums.append(rest)

    cnt = len(nums) -1
    # 从后往前遍历 nums
    for num in reversed(nums):
        if num!=0:
            print(str(num)+"*"+str(M)+"^"+str(cnt),end="")
            if tot:
                print('+',end='')
                tot -= 1
        cnt -= 1

s = input() # 表示输入值，输入得到的其实是一个字符串
s = s.split() # 转换成列表
transform(int(s[0]),int(s[1]))


