/*
Given the array of integers and number m. Find number of subarray having xor as m.

Input : 
m = 6
A[] = {4,2,2,6,4}
op: 4
Explanation: subarray having xor as 6 are [6], [2,2,6],[4,2,2,6,4],[4,2]
*/
#include<bits/stdc++.h>
using namespace std;

int numofxor(int *a,int n,int k)
{
    map<int,int> m;
    int xorr=0,c = 0;
    for(int i=0;i<n;i++)
    {
        xorr = xorr^a[i];
        if(xorr == k)
        c++;
        if(m.find(xorr^k)!=m.end())
        {
            c += m[xorr^k];
        }
        m[xorr] += 1;
    }
    return c;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int m;
    cin>>m;
    int r = numofxor(a,n,m);
    cout<<r<<endl;

    return 0;
}