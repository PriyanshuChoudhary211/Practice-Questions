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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *ptr = head,*ptr2 = head->next;
        vector<int>nums1,nums2;
        while(ptr )
        {
            nums1.push_back(ptr->val);
            ptr=ptr->next==NULL?NULL:ptr->next->next;
        }
        while(ptr2)
        {
            nums2.push_back(ptr2->val);
            ptr2=ptr2->next==NULL?NULL:ptr2->next->next;

        }
        ListNode *res = new ListNode(0);
        ListNode *ret = res;
        int i = 0, j = 0;
        while(i<nums1.size() && j<nums2.size())
        {
            res->next = new ListNode(nums2[i]);
            res = res->next;
            res->next = new ListNode(nums1[j]);
            res = res->next;

            i++;j++;
        }
        if(i<nums1.size())
          
        {
            res->next = new ListNode(nums1[i]);
            res = res->next;
        }
          if(j<nums2.size())
          
        {
            res->next = new ListNode(nums2[j]);
            res = res->next;
        }
        
         return ret->next;
    }
};

*/
