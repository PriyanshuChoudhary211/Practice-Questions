/**
class MyHashMap {
public:
    struct node
    {
        int k;
        int v;
        struct node *next;
    }*head,*tail;    
    MyHashMap() {
        head = NULL;
        tail = NULL;
    }
    
    void put(int key, int value) {
        if(get(key)==-1)
        {
            node *newNode = new node();
            newNode->k = key;
            newNode->v = value;
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
            return;
        }
        else
        {
            node *ptr = head;
            while(ptr)
            {
                if(ptr->k == key)
                {
                    ptr->v = value;
                    return;
                }
                ptr = ptr->next;
            }
        }
    }
    
    int get(int key) {
        node *ptr = head;
        while(ptr)
        {
            if(ptr->k == key)
            {
                return ptr->v;
            }
            ptr = ptr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        node *ptr = head,*temp = head;
        if(head == NULL )
            return ;
        if(key == head->k)
        {
            head = head->next;
            delete(temp);
            temp = head;
            return;
        }
        ptr = ptr->next;
        while(ptr)
        {
            if(ptr->k == key)
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
};


 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */