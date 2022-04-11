# Definition for singly-linked list.
from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def rotateRight(self, head: ListNode, k: int) :
        if head is None:
            return head
        length = 0
        ori = tmp = head # 原始头结点
        pre = None
        while(head is not None):
            pre = head 
            head = head.next
            length += 1
        # print(length)
        
        k %= length
        cnt = 1
        # 找到合适的地方
        while(cnt < length - k):
            tmp = tmp.next
            cnt += 1
        
        start = tmp.next
        if start is None:
            return ori
        tmp.next = None
        pre.next = ori
        return start

s = Solution()
node3 = ListNode(2,None)
node2 = ListNode(1,node3)
head = ListNode(0,node2)
out = s.rotateRight(head,k=3)
while(out):
    print(out.val)
    out = out.next
