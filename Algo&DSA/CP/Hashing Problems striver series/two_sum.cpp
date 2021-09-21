// In this given an array and target and have to return array positions from array
// #include <bits/stdc++.h>
// using namespace std;
// vector<int> tsum(int *a, int t, int n)
// {
//     vector<int> res;
//     unordered_map<int,int> m;
//     for(int i=0;i<n;i++)
//     {
//         if(m.find(t-a[i])!=m.end())
//         {
//         res.push_back(m[t-a[i]]);
//         res.push_back(i);
//         return res;
//         }
//         m[a[i]] = i;

//     }
//     return res;
// }
// int main()
// {
    // int n,target;
    // cin>>n;
    // int a[n];
    // for(int i=0;i<n;i++)
    // {
    //     cin>>a[i];
    // }
    // cin>>target;
    // vector<int> v =tsum(a,target,n); 
    // for(auto it = v.begin();it!=v.end();it++)
    // {
    //     cout<<*(it)<<" ";
    // }2;
//     return 0;
// }
// 0 0 1
// 0 1 0
// += 0 1 1 => 3

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gcd(x,y) __gcd(x,y)

bool comp(int a,int b)
{
    return (a>b);
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	int l = s.size();
	if(l<7) cout<<"NO";
	else
	{
	    int c0=0,c1=0;
	   for(int i=0;i<l-1;i++)
	   {
	       if(s[i]==s[i+1]&& s[i]==48)
	       {
	           c0++;
	           for(int j=i+2;j<l;j++)
	           {
	               if(s[i]==s[j])
	               c0++;
	               else
	               {
	                c0 =0;
	                break;
	               }
	           }
	       }
	       else if(s[i]==s[i+1]&& s[i]==49)
	       {
	           c1++;
	           for(int j=i+2;j<l;j++)
	           {
	               if(s[i]==s[j])
	               c1++;
	               else
	               {
	                c1 =0;
	                break;
	               }
	           }
	       }
	   }
	}
	if(c1>=7 || c0>=7) cout<<"YES";
	else cout<<"NO";
   return 0;
}
