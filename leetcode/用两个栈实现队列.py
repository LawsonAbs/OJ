from queue import Queue

class CQueue:

    def __init__(self):
        #self.queue = Queue(maxsize=0) # 无最长限制
        self.stack1 = [] # 用于保持和队列正常的顺序
        self.stack2 = []

    def appendTail(self, value: int) -> None:
        self.stack1.append(value)
        # self.stack2.append(value)  # 二者存值顺序相同
        return        

    def deleteHead(self) -> int:
        # 出栈首
        if len(self.stack1) == 0:
            return -1
        
        else: # 可以真正删除
            while(len(self.stack1) > 1):
                self.stack2.append(self.stack1.pop()) # 依次将数据放入到stack2中

            # 删除最后一个元素
            del self.stack1[0]

        # 再归原位
        while(len(self.stack2)):
            self.stack1.append(self.stack2.pop())

    def print_queue(self):
        print(self.stack1)

# Your CQueue object will be instantiated and called as such:
obj = CQueue()
obj.appendTail(value)
param_2 = obj.deleteHead()