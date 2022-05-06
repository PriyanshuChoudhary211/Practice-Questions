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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head == NULL || head->next == NULL)
            return head;
        int count = 1;
        ListNode *ptr = head->next,*ptr2 = NULL,*tail = head;
        while(ptr)
        {
            count++;
            ptr = ptr->next;
            tail = tail->next;
            
        }
        ptr = head;
        int m = k%count;
        count=abs(count-m);
        
        if(m!=0)
        {
            while(count>1)
            {
                ptr=ptr->next;
                count--;
            }
            ptr2 = ptr->next;
            ptr->next = NULL;
            tail->next = head;
            head = ptr2;
        }
        
   return head;
        
    }
};

*/
