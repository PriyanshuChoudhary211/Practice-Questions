/*
class MyCircularDeque {
public:
     struct Node
    {
        int val;
        Node *next;
    }*head,*tail;
    int size=0,node;
    MyCircularDeque(int k) {
        head = NULL;
        tail = head;
        size = k;
        node=0;
    }
    
    bool insertFront(int value) {
        if(node == size)
            return false;
        Node *newNode = new Node();
        newNode->val = value;
        newNode->next = NULL;
        
        if(head == NULL)
        {
            head = newNode;
            tail = head;
            tail->next = head;
           
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
            
        }
        node++;
        return true;
    }
    
    bool insertLast(int value) {
         if(node<size)
        {
            Node *newNode = new Node();
            newNode->val = value;
            newNode->next = newNode;
            if(head == NULL)
            {
                head = newNode;
                tail = head;
                tail->next = head;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
                tail->next = head;
            }
            node++; 
            return true;
        }
        else
            return false;
    }
    
    bool deleteFront() {
         if(node == 0)
            return false;
        if(node == 1)
        {
            Node *temp = head;
            head = NULL;
            tail=NULL;
            delete(temp);
            node--;
            return true;
        }
        Node *temp = head;
        head = head->next;
        delete(temp);
        tail->next = head;
        node--;
        return true;
    }
    
    bool deleteLast() {
        if(node == 0)
            return false;
        if(node == 1)
        {
             delete(head);
             head = NULL;
            tail = NULL;
        }
        else
        {
            Node *ptr = head;
            while(ptr->next!=tail)
            {
                ptr=ptr->next;
            }
            ptr->next = head;
            delete(tail);
            tail = ptr;
            
        }
        node--;
        return true;        
    }
    
    int getFront() {
         if(head)
        return head->val;
        
        return -1;
    }
    
    int getRear() {
          if(!tail)
            return -1;
        return tail->val;
    }
    
    bool isEmpty() {
         if(!head)
            return true;
        
        return false;
    }
    
    bool isFull() {
         if(node == size)
            return true;
        else return false;
    }
};

 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */