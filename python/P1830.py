def readToArray():
    s = input()
    nums = s.strip().split()
    nums = [int(num) for num in nums]
    return nums
n,m,x,y = readToArray()[0:4]

arr = [[0 for i in range(m+5)] for j in range(n+5)] # 使用一个二维数组 N*M 存储各个坐标被炸的情况
flag = [[0 for i in range(m+5)] for j in range(n+5)] # 使用一个二维数组 N*M 存储各个坐标被炸的情况

# 输入炸掉的坐标
for i in range(x):
    lx,ly ,rx,ry = readToArray()[0:4] # 得到左上右下的坐标
    for k in range(lx,rx+1):
        for j in range(ly ,ry+1):
            arr[k][j]+=1;
            flag[k][j] = i+1

# 输入
for i in range(y):
    qx,qy = readToArray()[0:2]
    if arr[qx][qy] != 0:
        print("Y",arr[qx][qy],flag[qx][qy])
    else:
        print("N",)