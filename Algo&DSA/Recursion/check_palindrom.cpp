/*
    Intution : 
    -->i n-i-1;
    if(i>=n/2)
    return true;
    if(s[i] == s[n-i-1])
    return check(s,i+1,n);
 */
#include <bits/stdc++.h>
using namespace std;

bool check(string s,int i)
{
    int size = s.size();
    if(i>=size/2) return true;
    if(s[i] == s[size -i- 1])
    return check(s,i+1);
    return false;

}

int main()
{
    string s;
    cout<<"Enter string : ";
    cin>>s;
    if(check(s,0) == true)
    cout<<s<<" is a palindrom\n";
    else cout<<s<<" is not a palindrom\n";
    return 0;
}
