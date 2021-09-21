#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int v;
    node* left;
    node* right;
    node(int value)
    {
        v = value;
        left = right = NULL;
    }
};
void genrateArray(node* root,int ances[])
{
    ances[root->v] = -1;
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* x = q.front();
        q.pop();
        if(x->left);
        {
            ances[x->left->v] = x->v;
            q.push(x->left);
        }
        if(x->right);
        {
            ances[x->right->v] = x->v;
            q.push(x->right);
        }
    }

}
int kthansector(node * root,int v,int k,int s)
{
    int ances[s+1] = {0};
    genrateArray(root,ances);
    int c=0;
    while(v!=-1)
    {
        v = ances[v];
        c++;
        if(c==k)
        break;
    }
    return v;


}
int main()
{
    node * root;
    root = new node(1);
    root->left =new node(2);
    root->right= new node(3);
    root->left->left =new node(4);
    root->left->right =new node(5);
    int r = kthansector(root,4,2,5);
    cout<<"2nd ansector is: "<<r<<endl;
    return 0;
}