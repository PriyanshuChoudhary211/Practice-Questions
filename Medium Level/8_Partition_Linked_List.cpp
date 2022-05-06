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
    ListNode* partition(ListNode* head, int x) {
        ListNode *res = new ListNode(0);
        ListNode *ret = res;
        ListNode *ptr = head,*hold=NULL;
           while( ptr && ptr->val < x)
            {
                res->next = new ListNode(ptr->val);
                res = res->next;
               ptr = ptr->next;
            }
           hold = ptr;
              while(ptr)
              {
                  if(ptr->val<x)
                  {
                    res->next = new ListNode(ptr->val);
                    res = res->next;
                  }
                   ptr = ptr->next;   
              }  
        while(hold)
        {
            if(hold->val>=x)
            {
                 res->next = new ListNode(hold->val);
                    res = res->next;
            }
            hold = hold->next;
        }
      return ret->next;
    }
};


*/
