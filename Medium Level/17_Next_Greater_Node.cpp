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
    ListNode* reverse_List(ListNode *head)
    {
        ListNode *ptr = head,*temp = NULL;
        while(ptr)
        {
            ptr=head->next;
            head->next = temp;
            temp = head;
            head = ptr;
        }
        return temp;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        head = reverse_List(head);
        stack<int>s;
        ListNode *ptr = head;
        while(ptr)
        {
            if(s.empty())
            {
                s.push(ptr->val);
                ans.push_back(0);
                ptr = ptr->next;
            }
            else if(s.top()>ptr->val)
            {
                ans.push_back(s.top());
                s.push(ptr->val);
                ptr = ptr->next;
                
            }
            else
            {
                s.pop();
            }
            
        }      
        reverse(ans.begin(),ans.end());
        return ans;
    
    }
}; */