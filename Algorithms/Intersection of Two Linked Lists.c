/*
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 *
 *
 * For example, the following two linked lists:
 *
 * A:            a1 → a2
 *  ↘            |
 *   c1 → c2 → c3
 *  ↗            |
 * B:            b1 → b2 → b3
 * begin to intersect at node c1.
 *
 *
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 * Credits:
 * Special thanks to @stellari for adding this problem and creating all test cases.
*/

/****************************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* res = NULL, *aCur = headA, *bCur = headB;
    int    aLen = 0, bLen= 0, ext = 0;
    
    if (aCur == NULL || bCur == NULL)
    {
        return NULL;
    }
    
    for (; aCur; aCur = aCur->next, aLen++);
    for (; bCur; bCur = bCur->next, bLen++);
    aCur = headA;
    bCur = headB;
    
    if (aLen >= bLen)
    {
        ext = aLen - bLen;
        for (int i = 0 ; i < ext; i++)
        {
            aCur = aCur->next;
        }
    }
    else
    {
        ext = bLen - aLen;
        for (int i = 0; i < ext; i++)
        {
            bCur = bCur->next;
        }
    }
    
    for(; aCur; aCur = aCur->next, bCur = bCur->next)
    {
        if (aCur->val == bCur->val)
        {
            break;
        }
    }
    return aCur;
}