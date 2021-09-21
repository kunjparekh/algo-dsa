/*
you are given a string s, find the length of longest substring without reapting character.
inp : "abcabcbb"
op: 3  
*/

#include<bits/stdc++.h>
using namespace std;

int length(string s)
{
    vector<int> v(256,-1);
    int len = 0,left = 0,right = 0;
    while(right<s.size())
    {
        if(v[s[right]]!=-1) left = max(left,v[s[right]]+1);
       len = max(len, right-left+1);
       v[s[right]] = right;
       right++;
       //cout<<"r:"<<right<<" l:"<<left<<endl;
    }
    return len;
}
int main()
{  
    string s;
    cin>>s;
    int r = length(s);
    cout<<r<<endl;
    return 0;
}
