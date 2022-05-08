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
    ListNode *merge(ListNode* left , ListNode *right)
    {
        ListNode *l = left,*r = right;
        ListNode *head2 = new ListNode(0);
        ListNode *res = head2;
        while(l && r)
        {
            if(l->val <= r->val)
            {
                head2->next = new ListNode(l->val);
                head2 = head2->next;
                l = l->next;
            }
            else
            {
                 head2->next = new ListNode(r->val);
                head2 = head2->next;
                r = r->next;
            }
        }
        while(l)
        {
              head2->next = new ListNode(l->val);
                head2 = head2->next;
                l = l->next;
        }
        while(r)
        {
             head2->next = new ListNode(r->val);
                head2 = head2->next;
                r = r->next;
        }
        return res->next;
    }
    ListNode *merge_sort(vector<ListNode*>&lists,int l,int r)
    {
        ListNode *left = NULL, *right = NULL;
        ListNode *head = NULL;
        if(l == r)
            return lists[l];
        if(l<r)
        {
            int mid = l + (r-l)/2;
            left = merge_sort(lists,l,mid);
            right = merge_sort(lists,mid+1,r);
            return merge(left,right);            
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int l = 0,r = lists.size()-1;
        ListNode *head = merge_sort(lists,l,r);
        return head;
    }
};

*/