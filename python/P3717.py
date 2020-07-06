import math # 引入数学计算的包
N=105
arr = [[0 for i in range(N)] for i in range(N)]

def readToArray():
    s=input()
    nums = s.strip().split()
    nums = [int(num) for num in nums]
    return nums


# 判断坐标(x,y)是否在其中
def judge(li):
    cnt = 0
    for i in range(1, n + 1):
        for j in range(1, n + 1): # 前两层是遍历矩阵
            for k in li: # 遍历tuple
                #print(k)
                x,y = k[0:2] # 拿到一个tuple
                dis = (x-i)*(x-i) + (y-j)*(y-j)
                dis = math.sqrt(dis)
                if dis<=r  and arr[i][j] == 0:
                    arr[i][j] = 1
                    cnt += 1
    print(cnt)

n, m, r = readToArray()[0:3]
li = []
for i in range(m):
    x,y=readToArray()[0:2] # 获取坐标
    li.append((x,y)) # 放入一个list中

judge(li)
