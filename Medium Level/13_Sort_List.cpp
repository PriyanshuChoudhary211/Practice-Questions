/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 
class Solution {
public:
    ListNode *merge(ListNode *l,ListNode *r)
    {
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
    ListNode *findMid(ListNode *head)
    {
        ListNode *f=head->next,*s=head;
        while(f && f->next)
        {
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next==NULL)
            return head;
        ListNode *l = head,*r = NULL;
        ListNode *m = NULL;
       
        m = findMid(head);
        r = m->next;
        m->next = NULL;
        l = sortList(l);
        r = sortList(r);
        
        ListNode *result = merge(l,r);
        
        return result;
        
        
    }
};

*/