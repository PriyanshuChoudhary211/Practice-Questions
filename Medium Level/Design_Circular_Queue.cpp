/*
class MyCircularQueue {
public:
    struct Node
    {
        int val;
        Node *next;
    }*head,*tail;
    int size=0,node;
    MyCircularQueue(int k) {
        head = NULL;
        tail = head;
        size = k;
        node=0;
    }
    
    bool enQueue(int value) {
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
    
    bool deQueue() {
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
    
    int Front() {
        if(head)
        return head->val;
        
        return -1;
    }
    
    int Rear() {
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

*/
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */