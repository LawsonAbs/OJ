class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = [] # 使用一个列表
        self.min_data = [] # 栈中的最小值，也是一个序列

    def push(self, x: int) -> None:
        self.data.append(x)
        if len(self.min_data) == 0:
            self.min_data.append(x)
        else:            
            self.min_data.append(min(self.min_data[-1],x))
    
    def pop(self) -> None:        
        if len(self.data):
            self.data.pop()
            self.min_data.pop()
        else:
            return None

    def top(self) -> int:
        if len(self.data) == 0:
            return None
        
        return self.data[-1]

    def min(self) -> int:
        return self.min_data[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.min()