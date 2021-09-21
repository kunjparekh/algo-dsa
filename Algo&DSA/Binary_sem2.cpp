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
    node *create();
    void Inorder(node *);
    void Deletedeep(node *, node *);
    node *del(node *, int);
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
node *Binary_Tree::del(node *root, int val)
{
    if (root == NULL)
        return NULL;
    if (!root->left && !root->right)
    {
        if (root->v = val)
        {
            delete root;
            root = NULL;
            return root;
        }
        return root;
    }
    queue<node *> q;
    q.push(root);
    node *key_node = NULL;
    node *curr = NULL;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr->v == val)
        {
            key_node = curr;
        }
        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
            q.push(curr->right);
    }
    if (key_node)
    {
        key_node->v = curr->v;
        Deletedeep(root, curr);
    }
    return root;
}
void Binary_Tree::Deletedeep(node *root, node *curr)
{
    if (root == NULL)
        return;
    if (root==curr)
    {
        delete root;
        root = NULL;
        return;
    }
    if (root->left == curr)
    {
        delete curr;
        root->left = NULL;
        return;
    }
    if (root->right == curr)
    {
        delete curr;
        root->right = NULL;
        return;
    }
    Deletedeep(root->left, curr);
    Deletedeep(root->right, curr);
}
int main()
{
    node *root = NULL;
    Binary_Tree t;
    cout << "Enter the root" << endl;
    root = t.create();
    t.Inorder(root);
    int x;
    cout << "Enter the value to delete: " << endl;
    cin >> x;
    root = t.del(root, x);
    t.Inorder(root);
    return 0;
}
