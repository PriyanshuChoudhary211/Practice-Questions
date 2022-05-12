#include<bits/stdc++.h>
using namespace std;
class btNode
{
  private:
        btNode *left;
        int data;
        btNode *right;
  public:
        btNode *root = NULL;
        btNode()
        {
            left = NULL;
            right = NULL;
        }
        btNode *create()
        {
            int x;
            cout<<"Enter value to insert";
            cin>>x;
            btNode *newNode = new btNode();
            newNode->data = x;
            newNode->left = NULL;
            newNode->right = NULL;
            
            if(x == -1)
            return 0;

            cout<<"Enter the left Child of: "<<newNode->data<<endl;
            newNode->left = create();
            cout<<"Enter the right child of: "<<newNode->data<<endl;
            newNode->right = create();

            return newNode;
            
        }
        void preOrder(btNode *root)
        {
            if(root)
            {
                cout<<root->data<<" ";
                preOrder(root->left);
                preOrder(root->right);
            }
            return;
        }
        void postOrder(btNode *root)
        {
            if(root)
            {
                postOrder(root->left);
                postOrder(root->right);
                cout<<root->data<<" ";
            }
        }
        void inOrder(btNode *root)
        {
            if(root)
            {
                inOrder(root->left);
                cout<<root->data<<" ";
                inOrder(root->right);
                
            }
        }
        int countDepth(btNode *root)
        {
            if(root == NULL) return 0;
            int left = 1+countDepth(root->left);
            int right = 1+countDepth(root->right);
            return max(left,right);
        }


};

int main()
{
    btNode Bt,*root=nullptr;
    root = Bt.create();
    Bt.preOrder(root);
  
    cout<<endl;
    cout<<"Depth is: ";
    cout<<Bt.countDepth(root);
}
