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
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head != NULL && head->val == val)
        {
            head = head->next;
        }
        if(head == NULL)
            return head;
        
        ListNode *ptr = head,*ptr2 = head->next;
        while(ptr && ptr2)
        {
            if(ptr2->val == val)
            {
                ptr->next = ptr2->next;
            }
            else
            {
                
                  ptr = ptr->next;
            }
             ptr2 = ptr2->next;
        }
        
        return head;
    }
};

*/