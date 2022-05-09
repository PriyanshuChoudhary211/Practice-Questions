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
    int node_count(ListNode *head)
    {
        int count=0;
        ListNode *ptr = head;
        while(ptr)
        {
            ptr = ptr->next;
            count++;
        }
        return count;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*>ans;
        if(head == NULL)
        {
            for(int i = 0; i<k;i++)
                ans.push_back(NULL);
            
            return ans;
        }
        ListNode *ptr = head,*ptr2 = head->next;
        int count = node_count(head);

        int mod = count%k;
        int node = count/k;
        int max = node+1;
        
        for(int i = 0;i<mod;i++)
        {
            ans.push_back(ptr);
            for(int j = 1;j<max;j++)
            {
                ptr = ptr2;
                ptr2=ptr2->next;
            }
            ptr->next = NULL;
            ptr = ptr2;
            ptr2 = ptr2?ptr2->next:NULL;
        }
        for(int i = 0; i<k-mod;i++)
        {
            ans.push_back(ptr);
            for(int j = 1 ; j < node ; j++)
            {
                ptr = ptr2;
                ptr2 = ptr2->next;
            }
            if(ptr)
            ptr->next = NULL;
            ptr = ptr2;
            ptr2 = ptr2?ptr->next:NULL;
        }  
        return ans;
    }
};

*/