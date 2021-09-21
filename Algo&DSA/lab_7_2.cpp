#include <bits/stdc++.h>
using namespace std;

class Binary_Tree;
class node
{
    int v;
    node *left;
    node *right;

public:
    node(int v)
    {
        this->v = v;
        left = NULL;
        right = NULL;
    }
    node()
    {
        left = right = NULL;
    }
    friend class Binary_Tree;
};

class Binary_Tree
{
public:
    int c=0;
    node *create();
    void Inorder(node *);
    int Max(node *);
    void revrselevel(node*);
    int halfnode(node*);
    int Height(node*);
    int diameter(node*);
};
node *Binary_Tree::create()
{
    int v;
    cin >> v; //Take that value form the user
    if (v == -1)
        return NULL;
    node *root = new node(v);
    cout << "Enter the left " << root->v << ": ";
    root->left = create();
    cout << "Enter the right " << root->v << ": ";
    root->right = create();
    return root;
}
void Binary_Tree::Inorder(node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->v << " ";
    Inorder(root->right);
}
int Binary_Tree::Max(node * root)
{
    if(root==NULL)
    return -1;
    int m = root->v;
    int l = Max(root->left);
    int r = Max(root->right);
    if(l>m)
    m = l;
    if(r>m)
    m = r;
    return m;
}
void Binary_Tree::revrselevel(node* root)
{
    if(root==NULL)
    return;
    if(!root->left && !root->right)
    cout<<root->v<<endl;
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    while(!q.empty())
    {
        node *c = q.front();
        q.pop();
        s.push(c);
        if(c->right)
        q.push(c->right);
        if(c->left)
        q.push(c->left);
    }
    while(!s.empty())
    {
        node *p = s.top();
        s.pop();
        cout<<p->v<<" ";
    }
}
int Binary_Tree::halfnode(node* root)
{
    if(root==NULL)
    return 0;
    if(root->left!=NULL && root->right==NULL)
        c++;
    if(root->right!=NULL && root->left==NULL)
        c++;
    halfnode(root->left);
    halfnode(root->right);
    return c;
}
int Binary_Tree::Height(node* root)
{
    if(root==NULL)
    return 0;
    int h = max(Height(root->right),Height(root->left)) +1;
    return h;
}
int Binary_Tree::diameter(node* root)
{
    if(root==NULL)
    return 0;
    int lheight = Height(root->left);
    int rheight = Height(root->right);
    int lDiameter = diameter(root->left);
    int rDiameter = diameter(root->right);
    int currDiameter = lheight+rheight+1;
    int Diameter = max(currDiameter, max(lDiameter,rDiameter));
    return Diameter;
}
/*   1
   /   \
   2    3
  /      \ 
  4      5
*/
int main()
{
    node *root = NULL;
    Binary_Tree t;
    cout << "Enter the root" << endl;
    root = t.create();
    t.Inorder(root);
    int maxi = t.Max(root);
    cout<<endl<<maxi<<endl;
    t.revrselevel(root);
    cout<<"\nHalf Node: "<<t.halfnode(root)<<endl;
    //cout<<"\nH: "<<t.Height(root)<<endl;
    cout<<"\nD: "<<t.diameter(root)<<endl;
    
    return 0;
}