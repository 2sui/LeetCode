/*
 * Reverse a singly linked list.
 */

/****************************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if ((NULL == head) || (NULL == head->next)) return head;
    struct ListNode *tmp, *cur = head;
    cur = head->next;
    head->next = NULL;
    
    for (; cur;)
    {
        tmp = cur;
        cur = cur->next;
        tmp->next = head;
        head = tmp;
    }
    
    return head;
    
}