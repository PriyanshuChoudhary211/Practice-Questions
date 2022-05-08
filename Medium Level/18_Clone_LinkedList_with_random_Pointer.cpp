/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node *ptr = head,*front=NULL;
        
        // Copy creation
        while(ptr)
        {
            front = ptr->next;
            Node *copy = new Node(ptr->val);
            ptr->next = copy;
            copy->next = front;
            ptr = front;            
        }
        //Random initialisation
        ptr = head;
        while(ptr)
        {
            ptr->next->random = ptr->random!=NULL?ptr->random->next:NULL;
            ptr = ptr->next->next;
        }
        ptr = head;
        //Correction of Main list
        Node *dummy = new Node(0);
        dummy->next = ptr->next;
        
        Node *ptr2=dummy->next;
         front = ptr2->next;
        
        while(ptr)
        {
            ptr->next = ptr2->next;
            ptr2->next = front==NULL?NULL:front->next;
            ptr = front;
            front = front==NULL?NULL:front->next->next;
            ptr2 = ptr2->next;
        }
        
        return dummy->next;
    }
};

*/