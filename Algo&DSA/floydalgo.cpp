#include<bits/stdc++.h>
using namespace std;
/*Floyd's || Tortoise hair algo
  ->for detecting cycle move fast pointer twice than slow pointer.
  ->for removing cycle make (after detecting cycle)one fast pointer head and move both untill 
    their next are same and finally in slow next should be NULL;
*/
struct node
{
    int data;
    node *next;
};
node *head=NULL;
node *r = new node;
void llist(int n)
{
    node *p = new node;
    if(head==NULL)
    {
        p->data = n;
        p->next  = NULL;
        head = p;
        r=p;
    }
    else //if(head->next==NULL)
    {
       r->next = p;
       p->data = n;
       p->next  = NULL;
       r=r->next;
    }
}

void makeCycle(int pos)
{
    node *t=head;
    node *p;
    int i=1;
    while(t->next!=NULL)
    {
        if(i==pos)
        {
            p = t;
        }
        i++;
        t=t->next;
    }
    t->next = p;
}
void disp()
{
    node *t = head;
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }

}
bool detectCycle()
{
    if(head==NULL)
    return false;
    node *slow = head;
    node *fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast = fast->next->next;
        if(slow==fast)
        return true;
        }
        return false;
}
void removeCycle()
{
    node *slow = head;
    node *fast = head;
    do
    {
      slow = slow->next;
      fast = fast->next->next;   
    } while (fast!=slow);
    fast = head;
    while(fast->next!=slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
    
}

int main()
{
    llist(1);
    llist(2);
    llist(3);
    llist(4);
    llist(5);
    llist(6);
    disp();
    makeCycle(3);
    (detectCycle())?cout<<"Cycle is present\n":cout<<"No Cycle\n";
    removeCycle();
    disp();
    return 0;
}