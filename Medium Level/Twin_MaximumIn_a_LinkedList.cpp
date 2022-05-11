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
    int pairSum(ListNode* head) {
        
        stack<int>s;
        ListNode* ptr = head;
        while(ptr)
        {
            s.push(ptr->val);
            ptr = ptr->next;
        }
        int x = s.size();
        x/=2;
        int sum = 0;
        ptr = head;
        int maxi = INT_MIN;
        while(x--)
        {
            sum = ptr->val + s.top();
            maxi = max(maxi,sum);
            s.pop();
            ptr = ptr->next;
        }
        return maxi;
        
    }
};

*/
