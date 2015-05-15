/*
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 */

/****************************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int i = 0;
    struct ListNode  *last = 0, lastNode;
    lastNode.next = head;
    
    for (struct ListNode *cur = head; cur; cur = cur->next)  i++;
    
    
    i = i - n;
    last = &lastNode;
    
    for (int j = 0; j < i; j++)
    {
        last = last->next;
    }
    
    if (last->next)
    {
        last->next = last->next->next;
    }
    
    return lastNode.next;
}