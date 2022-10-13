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
    void deleteNode(ListNode* node) {
        ListNode *ptr = node->next;
        // ListNode *temp = ptr;
        while(ptr!= NULL)
        {
            node->val = ptr->val;
             if(ptr->next == NULL || ptr==NULL)
            {
                node->next = NULL;
                break;
            }
            node=node->next;
            ptr=ptr->next;
           
        }
        delete(ptr);
        
    }
};