'''
写递归程序要有宏观的把握。
'''
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if head is None:
            return  []
        if head.next is None: 
            return head
        # step1. 得到一条链表的中点
        mid = self.splitList(head)
        
        # step2. 分别对左右两部分排序
        left = self.sortList(head) # 对左半部分排序
        right = self.sortList(mid) # 对右半边排序

        # step3. 将排好序的链表合并
        start = self.mergeList(left,right) # 将两条排好序的链表进行合并
        
        # step4. 返回最后合并后的头节点
        return start 

    # 将一条链表分成两个部分
    def splitList(self,head):
        slow = fast = head
        
        while(fast.next is not None and fast.next.next is not None):
            fast = fast.next.next
            slow = slow.next
        tmp = slow.next
        slow.next = None # 断开链表
        return tmp # 得到链表的中点


    # 合并两条链表，两条链表的头部分别是h1,h2
    def mergeList(self,h1,h2):
        if h1.val <= h2.val :
            start = h1
            h1 = h1.next
        else:
            start = h2
            h2 = h2.next
        res_head = start
        while(h1 is not None and h2 is not None):
            if h1.val <= h2.val:
                res_head.next = h1
                h1 = h1.next
            else:
                res_head.next = h2
                h2 = h2.next
            res_head = res_head.next
        if h1 is not None:
            res_head.next = h1
        if h2 is not None:
            res_head.next = h2
        return start


node4 = ListNode(4,None)
node3 = ListNode(1,node4)
node2 = ListNode(2,node3)
node1 = ListNode(3,node2)

s = Solution()
s.sortList(node1)