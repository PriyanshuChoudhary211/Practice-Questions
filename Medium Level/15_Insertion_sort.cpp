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
    ListNode* insertionSortList(ListNode* head) {
        if(head== NULL || head->next == NULL)
            return head;
        ListNode *h = head,*ptr = head->next,*temp = NULL,*ptr2=head,*ptr3=NULL;
        head->next = NULL;
        while(ptr)
        {
            if(ptr->val<=h->val)
            {
                temp = ptr->next;
                ptr->next = h;
                h = ptr;
                ptr = temp;
               
            }
            else
            {
                 ptr2 = h;
                temp = ptr->next;
                while(ptr2 && ptr2->val<ptr->val)
                {
                    ptr3 = ptr2;
                    ptr2 = ptr2->next;
                }
                ptr3->next = ptr;
                ptr->next = ptr2; 
               ptr = temp;              
                
            }
        }
        head = h;
        return head;
    }
};

*/