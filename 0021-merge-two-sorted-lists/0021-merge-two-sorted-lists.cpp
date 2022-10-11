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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *l = list1,*r = list2;
        
         if(l==NULL)
            return r;
        if(r == NULL)
            return l;
        
        ListNode *d = new ListNode(0);
        ListNode *res = d;
        
        while(l != NULL && r != NULL)
        {
            if(l->val < r->val)
            {
                d->next = l;
                d = l;
                l = l->next;
            }
            else
            {
                d->next = r;
                d = r;
                r = r->next;                
            }
        }
        while(l!=NULL)
        {
            d->next = l;
            d = l;
            l = l->next;
        }
         while(r!=NULL)
        {
            d->next = r;
            d = r;
            r = r->next;
        }
        
        return res->next;
    }
};