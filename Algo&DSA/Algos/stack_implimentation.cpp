#include <bits/stdc++.h>
using namespace std;
 
class Stack
{
  int *arr;
  int top;
  int capacity;
public:
Stack(int s);
~Stack( );
void push(int);
int pop();
int peek();
int size();
bool isEmpty();
bool isFull();
void sortinsert(int);
void sortStack();
void print();
};
Stack::Stack(int s)
{
  capacity = s;
  top = -1;
  arr = new int[s];
}
Stack::~Stack()
{
   delete[] arr;
}
void Stack::push(int val)
{
   if(top == capacity-1)
    cout<<" Stack is FULL!!\n";
  else
{
  top++;
  arr[top] = val;
}
}
void Stack::print()
{
for(int i=0;i<=top;i++)
{
  cout<< arr[i] <<" ";
}
cout<<endl;
}
int Stack::pop()
{
   int element = arr[top];
   top--;
   return element;
}
int Stack::peek()
{
   return arr[top];
}
int Stack::size() // This function returns current size of Stack [ returns currently how many elements are present //in Stack
{
   return top+1;
}
bool Stack::isEmpty()
{
  if(top==-1)
{
  return true;
}
return false;
}
bool Stack::isFull()
{
 if(top==capacity-1)
 {
      return true;
 }
return false;
}
 
/* I am using here recursive sorting technic to sort the Stack , I choose this technique as it follows all the Stack principal while sorting.
*/
 
void Stack::sortStack()
{
    if(!isEmpty())
    {
        int k = pop();// first we pop all the elements untill stack become empty
        sortStack();//this function call recursively for all inputs
        sortinsert(k);
    }
}
void Stack::sortinsert(int k)
{
    if(isEmpty() || k>(arr[top]))
    {
      push(k);
      return;
    }
    int l = pop();
    sortinsert(k);
    push(l);
}
 
int main()
{
   int s;
   cout<<"Enter the size of  Stack: ";
   cin >>s;
  int x;
  int choice;
   Stack obj(s);
   do
  {
   cout<<"Choose any option from below:\n\n\t1.push\n\t2.pop\n\t3.peek\n\t4.size of Stack \n\t5.Empty\n\t6.Full\n\t7.sort\n\t0. Exit"<<endl;
cin>>choice;
switch(choice)
{
   case 1:
{
 cout<<"enter element :";
    cin>>x;
    obj.push(x);
   break;
   }
case 2:
{ 
   int y= obj.pop();
   cout<<"Poped out element "<< y<<endl;
   break;
 
}
case 3:
{
  int z = obj.peek();
  cout<<z<<endl;
break;
}
case 4:
{
   int si = obj.size();
cout<<si<<endl;
break;
}
 
case 5:
{
bool r1  = obj.isEmpty();
 if(r1)
cout<<" Stack is empty "<<endl;
else
cout<<"Stack has some elements."<<endl;
 break;
   
 }
case 6:
{
  bool r2 = obj.isFull();
 if(r2)
cout<<"Stack is Full"<< endl;
else
cout<<"No tfull"<<endl;
break; 
}
case 7:
{
  obj.sortStack();
  obj.print();
  break;
}
case 8:
{
  cout<<"Exit"<<endl;
break;
}
}
}while(choice!=0);
 return 0; 
}
/*
 loop1 0<i<n
 {
     min = a[0] - a[1];
     if(min<0)
     min = min*(-1);
     loop2 2<j<n
     {
        x = a[i] - a[j];
        if(x<0)
        x = x*(-1);
        if(min<x)
        min = x;
        if(min == 0)
        break;
     }
 }
*/