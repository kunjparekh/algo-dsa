#include <bits/stdc++.h>
using namespace std;

void recur_revrese(int* a, int n,int i)
{
    //int *r = a;
    if(i>=(n/2))
    return ;
    swap(a[i],a[n-i-1]);
    return recur_revrese(a,n,i+1);
}
int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int a[n];
    cout<<"Enter the array elemnts: ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Array before reversal: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    recur_revrese(a,n,0);
    cout<<"Array after reversal: ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    return 0;
}