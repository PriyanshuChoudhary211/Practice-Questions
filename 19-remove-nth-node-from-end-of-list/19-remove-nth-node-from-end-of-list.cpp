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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* ptr = head,*ptr2 = NULL;
        while(ptr)
        {
            count++;
            ptr=ptr->next;
        }
        count = count-n;
        if(count==0)
        {
            head = head->next;
                return head;
        }
        ptr = head;
        while(count>1)
        {
            ptr=ptr->next;
            count--;
        }
        ptr2 = ptr->next;
        ptr->next = ptr2->next;
        delete(ptr2);
        return head;
        
    }
};