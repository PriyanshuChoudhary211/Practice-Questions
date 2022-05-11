/**
class MyHashSet {
public:
    struct node
    {
        int val;
        struct node *next;
    }*head,*tail;
    
    MyHashSet() {
        head = NULL; 
        tail = NULL;
    }
    
    void add(int key) {
        if(contains(key) == false)
        {
           node *newNode = new node();
            newNode->val = key;
            newNode->next = NULL;
            if(head == NULL)
            {
                head = newNode;
                tail = head;

            }
            else
            {
                tail->next = newNode;
                tail = tail->next;
            }
        }
        
    }
    
    void remove(int key) {
        node *ptr = head,*temp = head;
        if(head == NULL )
            return ;
        if(key == head->val)
        {
            head = head->next;
            delete(temp);
            temp = head;
            return;
        }
        ptr = ptr->next;
        while(ptr)
        {
            if(ptr->val == key)
            {
                temp->next = ptr->next;
                if(ptr == tail)
                {
                    tail = temp;
                }
                delete(ptr);
                return;
            }
            temp = ptr;
            
            ptr = ptr->next;
        }
    }
    
    bool contains(int key) {
        node *ptr = head;
        while(ptr)
        {
            if(ptr->val == key)
            {
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }
};


 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 * 
 * 
 */