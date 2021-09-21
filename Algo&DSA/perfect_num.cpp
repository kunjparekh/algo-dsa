#include<bits/stdc++.h>
using namespace std;
bool isPerfect(long long int n)
{
    // To store sum of divisors
    long long int sum = 1;
  
    // Find all divisors and add them
    for (long long int i=2; i*i<=n; i++)
    {
        if (n%i==0)
        {
            cout<<i*i<<endl;
            if(i*i!=n)
            {
                cout<<"inside"<<i*i<<endl;
                sum = sum + i + n/i;
                cout<<sum<<endl;
            }
            else
                sum=sum+i;
        }
    }
     // If sum of divisors is equal to
     // n, then n is a perfect number
     if (sum == n && n != 1)
          return true;
  
     return false;
}
  
// Driver program
int main()
{
    cout << "Below are all perfect numbers till 10000\n";
    //for (int n =2; n<10000; n++)
        if (isPerfect(28))
            cout << 28 << " is a perfect number\n";
    return 0;
}