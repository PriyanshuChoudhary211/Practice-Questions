/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *dummy = new ListNode(0,head);
        ListNode *p = dummy,*q=head,*r=head->next;
        while(r)
        {
            int fl = 0;
             while(r && q->val == r->val)
            {
                r= r->next;
                 fl = 1;
            }
            if(fl ==1)
            {
                p->next = r;
                q = r;
                r=r==NULL?NULL:r->next;
            }
            else
            {
                p = p->next;
                q = q->next;
                 r=r==NULL?NULL:r->next;
            }           
        }
        
        return dummy->next;
    }
};