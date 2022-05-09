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
    ListNode *reverse(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *ptr = head,*temp = NULL;
        while(ptr)
        {
            ptr = head->next;
            head->next = temp;
            temp = head;
            head = ptr;            
        }
        return temp;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        ListNode* head1 = reverse(l1);
        ListNode* head2 = reverse(l2);
        ListNode* ptr1 = head1,*ptr2 = head2;
        ListNode *head3 = new ListNode(0);
        ListNode *ptr3 = head3;
        
        int carry = 0;
        while(ptr1 && ptr2)
        {
            if((ptr1->val+ptr2->val+carry)<=9)
            {
                ptr3->next = new ListNode(ptr1->val+ptr2->val+carry);
                ptr3 = ptr3->next;
                carry = 0;
            }
            else if((ptr1->val+ptr2->val+carry)>9)
            {
                ptr3->next = new ListNode((ptr1->val+ptr2->val+carry)%10);
                ptr3 = ptr3->next;
                carry = 1;
            }
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }
        while(ptr1)
        {
             if((ptr1->val+carry)<=9)
            {
                ptr3->next = new ListNode(ptr1->val+carry);
                ptr3 = ptr3->next;
                 
                carry = 0;
            }
            else if((ptr1->val+carry)>9)
            {
                ptr3->next = new ListNode((ptr1->val+carry)%10);
                ptr3 = ptr3->next;
                carry = 1;
            }
            ptr1=ptr1->next;
        }
        while(ptr2)
        {
          
            if((ptr2->val+carry)<=9)
            {
                ptr3->next = new ListNode(ptr2->val+carry);
                ptr3 = ptr3->next;
                carry = 0;
            }
            else if((ptr2->val+carry)>9)
            {
                ptr3->next = new ListNode((ptr2->val+carry)%10);
                ptr3 = ptr3->next;
                carry = 1;
            }
            
            ptr2=ptr2->next;
        }
        if(carry)
        {
            ptr3->next = new ListNode(carry);
            ptr3 = ptr3->next;
        }
        
        head3 = reverse(head3->next);
        return head3;     
       
    }
};
 */
