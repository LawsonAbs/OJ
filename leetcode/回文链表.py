'''
使用快慢两个节点找出链表的中点，接着判断链表是否回文。

'''
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        
        start = slow = fast = head 
        while(fast.next is not None and fast.next.next is not None):
            fast = fast.next.next
            slow = slow.next
        second = slow.next
        slow.next = None
        # 对第二条链表翻转
        s_head = self.reverseLink(second)
        
        while(start is not None and s_head is not None):
            if start.val != s_head.val :
                return False
            start = start.next
            s_head = s_head.next
        
        return True

    # 翻转链表
    def reverseLink(self,head):
        cur = None
        pre = None
        while(head is not None):
            tmp = head.next
            head.next = cur
            pre = head
            cur = head            
            head = tmp
        return pre # 返回翻转后的链首

# node4 = ListNode(3,None)
# node3 = ListNode(2,node4)
# node2 = ListNode(2,node3)
node1 = ListNode(1,None)

s = Solution()
out = s.isPalindrome(node1)
print(out)