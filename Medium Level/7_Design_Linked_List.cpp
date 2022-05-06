/*

class MyLinkedList {
public:
    struct node
    {
        int val;
        struct node *next;
        
    }*head;
    int size;
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index<0 || index>=size)
            return -1;
        node *itr = head;
        while(index--)
        {
            itr = itr->next;
        }
        return itr->val;
    }
    
    void addAtHead(int val) {
        node *ptr = new node();
        ptr->val = val;
        ptr->next = NULL;
        if(head == NULL)
            head = ptr;
        
        else
        {      
            ptr->next = head;
            head = ptr;
        }
        size++;
    }
    
    void addAtTail(int val) {
        if(head == NULL)
        {
            head = new node();
            head->val = val;
            head->next = NULL;
        }
        else
        {
            node *ptr = new node();
            ptr->val = val;
            ptr->next = NULL;
            node *itr = head;
            while(itr->next)
                itr = itr->next;
            itr->next = ptr;
        }
        size++;
        
    }
    
    void addAtIndex(int index, int val) {
        if(index<0 || index>size)
            return;
        if(index == 0)
            addAtHead(val);
        else if(index == size)
            addAtTail(val);
        else{
        node *ptr = new node();
        ptr->val = val;
        ptr->next = NULL;
        
        node *itr = head;
        index--;
        while(index--)
        {
            itr = itr->next;
        }
        ptr->next = itr->next;
        itr->next = ptr;
        size++;
        }

    }
    
    void deleteAtIndex(int index) {
        if(index<0 || index >= size)
            return;
        node *itr = head;
        
        if(index == 0)
        {
            node *t = head;
            head = head->next;
            delete(t);
        }
        else
        {
            index--;
        while(index--)
        {
            itr = itr->next;
        }
        node *temp = itr->next;
        itr->next = temp->next;
        delete(temp);
        }
        size--;
    }
};

 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


