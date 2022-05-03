#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;

    void insert(Node **head,Node **tail, int k)
    {
       
         if(*head == NULL)
         {
              *head = new Node();
             (*head)->data = k;
             (*head)->next = NULL;
             *tail = *head;
         }
         else
         {
             Node *ptr = new Node();
             ptr->data = k;
             ptr->next = NULL;

             (*tail)->next = ptr;
             (*tail)= (*tail)->next;
         }
    }
    void display(Node *head)
    {
        Node *ptr = head;
        while(ptr)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
      void deleteNode(Node* node) {
        Node *ptr = node->next;
        // ListNode *temp = ptr;
        while(ptr!= NULL)
        {
            node->data = ptr->data;
             if(ptr->next == NULL || ptr==NULL)
            {
                node->next = NULL;
                break;
            }
            node=node->next;
            ptr=ptr->next;
           
        }
        delete(ptr);
        
    }
};
int main()
{
    Node list;
   Node *head = NULL;
   Node *tail = NULL;
   while(1)
   {
   cout<<"1. To insert more"<<endl;
   cout<<"2. To display"<<endl;
   cout<<"3. To Stop"<<endl;
   cout<<"4. Enter a position to dlt"<<endl;
   cout<<"Press any choice"<<endl;
    int m;
   int a;
   cin>>a;
   int k;
  
   switch (a)
   {
   case 1:
       cout<<"Enter number to insert"<<endl;
        cin>>k;
       list.insert(&head,&tail,k);
       break;
   case 2:
        list.display(head);
        break;
    case 3:
         exit(0);
         break;
    case 4:
        cout<<"Enter position of node"<<endl;
        cin>>m;
        Node* r = NULL;
        r = head;
        while(m>1)
        {
            r = r->next;
            m--;
        }
        list.deleteNode(r);
       break;
//    default:
//       cout<<"Invalid choice!!"<<endl;
//        break;
   }
   }
   
}