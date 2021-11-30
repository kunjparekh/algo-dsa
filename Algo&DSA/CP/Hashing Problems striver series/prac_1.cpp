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
int nf_required_subary(vector<int> &v, int k)
{
    int xorr=0,c = 0;
    map<int,int> m;
    for(auto it:v)
    {
        xorr = xorr^it;
        if(xorr == k)
        c++;
        if(m.find(xorr^k)!=m.end())
        c+=m[xorr^k];
        m[xorr]+=1;
    }
    return c;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
		int x;
		cin>>x;
        v.push_back(x);
    }
    int m;
    cin>>m;
    int r = nf_required_subary(v,m);
    cout<<r<<endl;

    return 0;
}
