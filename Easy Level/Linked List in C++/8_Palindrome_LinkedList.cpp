/*



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
    void reverse(ListNode **head2)
    {
        ListNode *ptr=*head2,*temp = NULL;
        while((*head2))
        {
            ptr = (*head2)->next;
            (*head2)->next = temp;
            temp = (*head2);
            (*head2) = ptr;
        }
        (*head2) = temp;
        
    }
    bool isPalindrome(ListNode* head) {
        ListNode *ptr = head,*ptr2=head;
        while( ptr2 && ptr2->next && ptr2->next->next )
        {
            ptr = ptr->next;
            ptr2 = ptr2->next->next;
        }
        ListNode *head2 = ptr->next;
        ptr->next = NULL;
        reverse(&head2);
        
        int flag = 0;
        while(head && head2)
        {
            if(head->val != head2->val)
            { 
                flag = 1;
                break;
            }
            head = head->next;
            head2=head2->next;
        }
        if(flag == 0)
        {
            return true;
            
        }
        else 
            return false;        
    }
};



*/