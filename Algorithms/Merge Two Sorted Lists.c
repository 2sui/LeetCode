/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 */

/****************************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL)  return l2;
    if (l2 == NULL)  return l1;
    struct ListNode resList, *l1Pos = l1, *l2Pos = l2, *cur = &resList;
    
    for (; !((NULL == l1) && (NULL == l2));) {
        
        if (NULL == l1 || NULL == l2) {
            
            if (NULL == l1) {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
                cur->next = 0;
                
            } else {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
                cur->next = 0;
            }
            continue;
        }
        
        if (l1->val == l2->val) {
            cur->next = l1;
            l1 = l1->next;
            cur->next->next = l2;
            l2 = l2->next;
            cur = cur->next->next;
            cur->next = 0;
            
        } else {
            
            if (l1->val > l2->val) {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
                cur->next = 0;
                
            } else {
                
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
                cur->next = 0;
            }
        }
    }
    
    return resList.next;
    
}