// In this given an array and have to find the longest consecutive sequence
#include <bits/stdc++.h>
using namespace std;
int cseq(vector<int> &v)
{
   set<int> s;
   for(int it:v)
   {
       s.insert(it);
   }
   int longestseq = 0;
   for(int it:s)
   {
       if(!s.count(it-1))
       {
           int currnum = it;
           int currentseq = 1;
       while (s.count(currnum+1))
       {
           currnum+=1;
           currentseq += 1;
       }
       longestseq = max(longestseq,currentseq);
       }
   }
   return longestseq;
}
int main()
{
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    int r = cseq(a);
    cout<<r<<endl; 
    return 0;
}