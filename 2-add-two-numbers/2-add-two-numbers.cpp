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
    void insert(ListNode **head,ListNode **tail,int key)
    {
        if((*head) == NULL)
        {
            *head = new ListNode();
            (*head)->val = key;
            (*head)->next = NULL;
            (*tail) = (*head);
        }
        else
        {
            ListNode *ptr = new ListNode();
            ptr->val = key;
            ptr->next = NULL;
            (*tail)->next = ptr;
            (*tail) = (*tail)->next;
        }
    }
        
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        Solution list;
        ListNode *head = NULL,*tail = NULL;
        ListNode *ptr1 = l1,*ptr2 = l2;
        int carry = 0;
        while(ptr1!=NULL && ptr2!=NULL)
        {
            if(ptr1->val + ptr2->val + carry<=9)
            {
                list.insert(&head,&tail,ptr1->val + ptr2->val+ carry);
                carry=0;
            }
            if(ptr1->val + ptr2->val + carry>9)
            {
                list.insert(&head,&tail,(ptr1->val + ptr2->val+ carry)%10);
                   carry=1;
            }     
               ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        while(ptr1)
        {
           if(ptr1->val + carry<=9)
            {
                list.insert(&head,&tail,ptr1->val + carry);
                carry=0;
            }
            if(ptr1->val + carry>9)
            {
                list.insert(&head,&tail,(ptr1->val + carry)%10);
                   carry=1;
            }     
            ptr1=ptr1->next;
                  
        }
         while(ptr2)
        {
           if(ptr2->val + carry<=9)
            {
                list.insert(&head,&tail,ptr2->val + carry);
                carry=0;
            }
            if(ptr2->val + carry>9)
            {
                list.insert(&head,&tail,(ptr2->val + carry)%10);
                   carry=1;
            }     
            ptr2=ptr2->next;       
        }
        if(carry ==1)
            list.insert(&head,&tail,carry);
        
        return head;
    }
};