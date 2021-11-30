//In this given an array and target and have to return array positions from array

#include <bits/stdc++.h>
using namespace std;
vector<int> tsum(int *a, int t, int n)
{
    vector<int> res;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        if(m.find(t-a[i])!=m.end())
        {
        res.push_back(m[t-a[i]]);
        res.push_back(i);
        return res;
        }
        m[a[i]] = i;

    }
    return res;
}
int main()
{
    int n,target;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>target;
    vector<int> v =tsum(a,target,n); 
    for(auto it = v.begin();it!=v.end();it++)
    {
        cout<<*(it)<<" ";
    }
    return 0;
}

