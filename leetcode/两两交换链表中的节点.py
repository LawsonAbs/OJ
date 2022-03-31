# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head is None:
            return 
        if head.next is None:
            return head
        start = head.next
        pre = None
        while(head):
            # 如果满足条件说明可以交换
            if head.next is not None:
                tmp_2 = head.next.next # 下次的head
                tmp_1 = head.next               
                tmp_1.next = head
                if pre is not None:
                    pre.next = tmp_1
                
                pre = head
                head.next = tmp_2
                head = tmp_2
            else:
                if pre is not None:
                    pre.next = head
                else: # 说明只有一个节点
                    pre = head
                head = head.next
            
        return start  # 返回头节点

node4 = ListNode(4,None)
node3 = ListNode(3,node4)
node2 = ListNode(2,node3)
node1 = ListNode(1,None)
s = Solution()
a = s.swapPairs(node1)
while(a):
    print(a.val,end="")
    a= a.next