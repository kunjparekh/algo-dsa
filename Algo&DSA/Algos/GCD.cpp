#include <bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    if(x<y)
    swap(x,y);
	if(y==0)
    return x;
    gcd(x%y , y);
}

int main()
{
    int r = gcd(20,5);
    cout<<r<<endl;
    return 0;
}

