
# 节点类
class Node():    
    def __init__(self,val,next):
        self.val = val
        self.next = next


# 单链表类
class SingleLink():
    def __init__(self):
        pass


# 反转链表，输入是链表头
# 迭代方法
def reverse_link(head):
    cur = None # 已经调整好的节点的末位指针 
    first = head # 链首
    while(head):
        next = head.next
        head.next = cur
        head = next # 获取下一轮的指针
        cur = head 
    
    while(first ):
        print(first.val)
        first = first.next 


