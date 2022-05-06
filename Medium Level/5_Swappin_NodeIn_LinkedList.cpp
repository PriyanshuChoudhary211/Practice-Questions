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
    ListNode* swapNodes(ListNode* head, int k) {
        int count= 0;
        ListNode *ptr = head;
        
        while(ptr)
        {
            count++;
            ptr = ptr ->next;
        }
         count = count-k+1;
        ListNode *t1=head, *t2 = head;
        while(k>1)
        {
            t1 = t1->next;
            k--;
        }
        while(count>1)
        {
            t2 = t2->next;
            count--;
        }
        swap(t1->val,t2->val);
        return head;
    }
};

*/