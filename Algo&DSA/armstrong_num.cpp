#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,c=0,result=0;
    cout<<"Enter The Number: ";
    cin>>n;
    int x = n;
    while(x>0)
    {
        x=x/10;
        c++;
    }
    x = n;
    while(x>0)
    {
        int r = x%10;
        result+=pow(r,c);
        x/=10;
    }
    
    if(result==n)
    cout<<"Amstrong Number\n";
    else cout<<"Not Amstrong Number\n";
    return 0;
}
