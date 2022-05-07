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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode *ptr = list1,*ptr2 = list1,*ptr3=list2;
        while(a>1)
        {
            ptr = ptr->next;
            a--;
        }
       
        while(b>0)
        {
            ptr2 = ptr2->next;  
            b--;
        }
         ptr->next = ptr3;
        while(ptr3->next)
        {
            ptr3 = ptr3->next;
        }
        ptr3->next = ptr2->next;
      
        return list1;
    }
};

*/