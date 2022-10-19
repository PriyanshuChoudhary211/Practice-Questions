/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode *a = headA;
        // ListNode *b = headB;
        // while(a!=b)
        // {
        //     a = a==NULL?headB:a->next;
        //     b = b==NULL?headA:b->next;
        // }
        // return a;
        stack<ListNode*>s1;
        stack<ListNode*>s2;
        ListNode *ptr1=headA,*ptr2=headB;
        ListNode *ans = NULL;
        while(ptr1!=NULL)
        {
            s1.push(ptr1);
            ptr1=ptr1->next;
        }
         while(ptr2!=NULL)
        {
            s2.push(ptr2);
            ptr2=ptr2->next;
        }
        while(!s1.empty() && !s2.empty() && s1.top() == s2.top())
        {
            ans=s1.top();
            s1.pop();
            s2.pop();
        }
        return ans;
        
    }
};