/*


class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* tmp = head -> next;
        ListNode* one = head -> next;
        ListNode* two = head -> next;
        while(two -> next) {
            two = two -> next;
            if(two -> next == NULL) {
                one -> next = NULL;
                return tmp;
            }
            if(two -> val == 0) {
                one -> next = two;
                one = one -> next;
            }
            one -> val += two -> val; 
        }
        return tmp;
    }
};


*/