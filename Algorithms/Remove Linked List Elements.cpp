/*
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 *
 * Credits:
 * Special thanks to @mithmatt for adding this problem and creating all test cases.
 */

/****************************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur = head, *last = cur;
        
        for (; NULL != cur;)
        {
            if (val == cur->val)
            {
                if (cur == head)
                {
                    last = cur->next;
                    cur->next = 0;
                    head = last;
                    cur = last;
                }
                else
                {
                    last->next = cur->next;
                    cur->next = 0;
                    cur = last->next;
                }
            }
            else
            {
                if (cur == head)
                {
                    last = cur;
                }
                else
                {
                    last = last->next;
                }
                
                cur = cur->next;
            }
        }
        return head;
    }
};