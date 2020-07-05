"""
递归求全排列
注意的问题：
01.我在本地运行程序可以跑出来结果，但是放在评测机上则出现RE的问题，说明可能是输入的数据导致的bug。
于是将input()改成了input().strip() 去掉其后的换行即可
"""
choice = [0 for i in range(10)] # 得到一个初始序列，用于存储递归的结果
vis=[0 for i in range(10)] #vis[i] 表i是否访问过
tot = 0 # 计数
suc = 0 # 是否成功的标志

# cnt表是已经访问了几个数
def permutation(cnt):
    global suc
    if suc :
        return
    if cnt == n:
        global tot
        tot += 1
        flag = 1
        # 判断是否相同
        for i in range(0,n):
            if choice[i] != nums[i]:
                flag = 0
                break
        if flag == 1: # 说明已经相等
            print(tot)
            suc = 1
            return

    # 递归遍历
    for i in range(1,n + 1): # 从1开始递归搜索
        if vis[i] != 1:
            choice[cnt] = i # 放入数字i
            vis[i] = 1
            permutation(cnt+1)
            vis[i] = 0

n = input()
n = int(n) # 得到数字n
nums = input().strip()  # 如果这里的.strip()去掉，则会得到一个RE的错误
nums=[int(num) for num in nums]
permutation(0) # 从0开始，但是因为后面的dfs从1开始，所以这里不用for循环

"""
3
231
4

3
123

9
789245136

9
987654321
362880

9
123456789
"""