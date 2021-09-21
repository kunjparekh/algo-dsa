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
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define gcd(x,y) __gcd(x,y)

// bool comp(int a,int b)
// {
//     return (a>b);
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	int n,m,maxi = 0,mini = 0;
// 	cin>>n>>m;
// 	vector<int> a;
// 	for(int i=0;i<m;i++)
// 	{
// 		int x;
// 		cin>>x;
// 	    a.push_back(x);
// 	}
// 	for(int i=n;i>=1;i++)
// 	{
// 	    maxi+=*max_element(a,a+n);
// 	    int index = distance(a,max_element(a,a+n));
// 	    a[index]--;
// 	}
// 	sort(a,a+n);
// 	int k=0;
// 	for(int i=n;i>=1;i++)
// 	{
// 	   mini+=a[i];
// 	   a[i]--;
// 	   if(a[k]==0)
// 	   k++;
// 	}
// 	cout<<maxi<<" "<<mini<<"\n";
	

//    return 0;
