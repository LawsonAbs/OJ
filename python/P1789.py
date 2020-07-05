# 读数据到数组中
def readToArray():
    s = input()
    nums = s.strip().split()
    nums = [int(num) for num in nums]
    return nums

n,m,k = readToArray()[0:3]
arr = [[0 for i in range(n+5)] for i in range(n+5)]

# 根据火把修改位置
def modifyFire(x,y):
    for i in range(-1,2):
        for j in range (-1,2):
            nx = x+i
            ny = y+j
            if nx>0 and nx<=n and ny >0 and ny <= n:
                arr[nx][ny] = 1 # 修改值

    # 修改零散点
    if y -2 > 0 :
        arr[x][y-2] = 1
    if x-2>0:
        arr[x-2][y] = 1
    if x+2 <= n:
        arr[x+2][y] = 1
    if y+2 <= n :
        arr[x][y+2] = 1

def modifyStone(x,y):
    for i in range(-2, 3):
        for j in range(-2, 3):
            nx = x + i
            ny = y + j
            if nx > 0 and nx <= n and ny > 0 and ny <= n:
                arr[nx][ny] = 1  # 修改值

#输入火把
for i in range(m):
    x,y = readToArray()[0:2]
    # 根据火把的位置遍历去修改数组
    modifyFire(x,y)

for i in range(k):
    x,y = readToArray()[0:2]
    modifyStone(x,y)

cnt = 0
for i in range(1,n+1):
    for j in range(1,n+1):
        if arr[i][j] == 0:
            cnt+=1
print(cnt)