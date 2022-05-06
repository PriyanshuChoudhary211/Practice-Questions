/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
*/

/*


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

/*

class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*>s;
        if(head == NULL || head->next== NULL)
            return;
        int count = 0;
        ListNode *ptr = head;
        while(ptr)
        {
            count++;
            ptr = ptr->next;
        }
        ptr = head;
        count/=2;
        while(count>=1)
        {
            ptr = ptr->next;
            count--;
        }
        ListNode *head2 = ptr->next;
        ptr->next = NULL;
        while(head2)
        {
            s.push(head2);
            head2=head2->next;
        }
        ptr = head;
        ListNode *ptr2 = NULL ;
        while(!s.empty())
        {
            ListNode *s2 = s.top();
            ptr2 = ptr->next;
            ptr->next = s2;
            s2->next =ptr2;
            s.pop();
            ptr = ptr->next->next;
        }
    }
};

*/

