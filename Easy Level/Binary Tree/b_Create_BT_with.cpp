#include<bits/stdc++.h>
using namespace std;
class btNode
{
    private:
        btNode *left,*right;
        int data;
        
    public:
        btNode()
        {
            left = right = NULL;
        }
        btNode *create(btNode *root)
        {
             int x;
             cout<<"Enter value:";
             cin>>x;
             btNode *n = new btNode();
             n->data = x;
             n->left = NULL;
             n->right = NULL;
             cout<<"Wanna insert more: (Y / N) ";
             char s;
             cin>>s;
             if(s == 'Y' || s == 'y')
             {
                cout<<endl<<"Enter left child of "<<n->data<<"...."<<endl;
                 n->left = create(n->left);
                 cout<<endl<<"Enter right child of "<<n->data<<"...."<<endl;
                 n->right = create(n->right);
             }
             else 
             {
                 n->left = NULL;
                 n->right = NULL;
             }
        return n;

        }
        void inorder(btNode *root)
        {
            if(root)
            {
                inorder(root->left);
                cout<<root->data;
                inorder(root->right);

            }
        }

};
int main()
{
    btNode *root,BT;
    root = BT.create(root);
    cout<<"Inorder is: ";
    BT.inorder(root);


    return 0;
}