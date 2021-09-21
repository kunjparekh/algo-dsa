/*
Given the array with positive and negative integers.The task is to compute largest subarray with sum 0.

Input : 
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
op: 5
*/
#include<bits/stdc++.h>
using namespace std;
int sum0(int *a, int n)
{
    int maxi =0,sum=0;
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum==0)
        {
            maxi = i+1;
        }
        else
        {
        if(m.end()==m.find(sum))
        {
            m[sum] = i;
        }
        else
        {
            maxi =max(maxi,i-m[sum]) ;
        }
        }
    }
    return maxi;
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
    int r = sum0(a,n);
    cout <<r<<endl;
    return 0;
}