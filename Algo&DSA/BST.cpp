#include<bits/stdc++.h>
using namespace std;

class node
{
    node *left;
    public:
    int v;
    node *right;
    node(int val)
    {
        v = val;
        this->left = NULL;
        this->right = NULL;
    }
    node()
    {
        this->left = NULL;
        this->right = NULL;
    }
    friend class BST;
};
class BST
{
    public:
    node* Insert(node*,int );
    void  Display(node *);
    node* Delete(node*,int );
    node *func(node*);
};
node* BST::Delete(node * root,int val)
{
    if(val<root->v)
    root->left = Delete(root->left,val);
    else if(val>root->v)
    root->right = Delete(root->right,val);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
        delete root;
        root = NULL;
        return root;
        }
        else if(root->left==NULL)
        {
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right==NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            node *temp = root;
            root = func(root->right);
            delete temp;
        }
    }
    return root;
}
node* BST::Insert(node* root,int val)
{
    if(root==NULL)
    {
        return new node(val);
    }
    if(val<root->v)
    {
        root->left = Insert(root->left , val);
    }
    else
    {
        root->right = Insert(root->right , val);
    }
    return root;
}
void BST::Display(node *root)
{
    if(root==NULL)
    {
        return;
    }
    Display(root->left);
    cout<<root->v<<" ";
    Display(root->right);
}
node* BST::func(node* root)
{
    while(root && root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}

int main()
{
    BST t;node s;
    node *root = NULL;
    char c;
    cout<<"1.Insert\n\n2.Delete\n\n3.display\n\n";
    do
    {
        cout<<"Enter your choice: "<<endl;
        int n,v,x;
        cin>>n;
        switch(n)
        {
        case 1:
            {
                cout<<"Enter the number to add in BST: "<<endl;
                cin>>v;
                if(root==NULL)
                {
                    root = t.Insert(root,v);
                }
                else
                {
                    t.Insert(root,v);
                }
                break;
            }
        case 2:
            {
               cout<<"Enter the number to delete from BST: "<<endl;
               cin>>v;
               node *p =t.Delete(root,v);
               t.Display(p);
               cout<<endl;
               break;
            }
        case 3:
            {
                cout<<"Tree elements in Inorder are: "<<endl;
                t.Display(root);
                cout<<endl;
                break;
            }
        default:
            cout<<"Invalid Choice: "<<endl;
        }
        cout<<"Do you want to enter any choice again?(y/n): "<<endl;
        cin>>c;
        }while(c=='y' || c=='Y');
        node *head = NULL;
        // cout<<"Converting BST into doubly linked list: "<<endl;
        // t.doublyll(root,&head);
        // t.printDLL(head);
        /*int k,l;
         cout<<"Enter two nodes values between which you want to find the distance: ";
                cin>>k>>l;
                int r = t.findist(root,k,l);
                cout<<"Distance between node "<<k<<" and "<<l<<" is: ";
                cout<<r<<endl;*/

    return 0;
}
