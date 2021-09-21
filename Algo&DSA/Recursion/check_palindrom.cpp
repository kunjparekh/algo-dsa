// /*
//     -->i n-i-1;
//     if(i>=n/2)
//     return true;
//     if(s[i] == s[n-i-1])
//     return check(s,i+1,n);
// */
// // #include <bits/stdc++.h>
// // using namespace std;

// // bool check(string s,int i)
// // {
// //     int size = s.size();
// //     if(i>=size/2) return true;
// //     if(s[i] == s[size -i- 1])
// //     return check(s,i+1);
// //     return false;

// // }

// // int main()
// // {
// //     string s;
// //     cout<<"Enter string : ";
// //     cin>>s;
// //     if(check(s,0) == true)
// //     cout<<s<<" is a palindrom\n";
// //     else cout<<s<<" is not a palindrom\n";
// //     return 0;
// // }

// /*
// -1 -1
// -1 -1 
// 1 -1 1
// -1 1 1
// 1 1 -1 
// */
// // #include <iostream>
// // using namespace std;

// // int main() {
// // 	int t;
// //     cin>>t;
// //     while(t--)
// //     {
// //         int n;
// //         cin>>n;
// //         if(n%2==0)
// //         {
// //             for(int i=0;i<n;i++)
// //             {
// //                 for(int j=0;j<n;j++)
// //                 {
// //                     cout<<"-1 ";
// //                 }
// //                 cout<<"\n";
// //             }
// //         }
// //         else
// //         {
// //             for(int i=0;i<n;i++)
// //             {
// //                 for(int j=0;j<n;j++)
// //                 {
// //                     if(i==j) cout<<"-1 ";
// //                     else cout<<"1 ";
// //                 }
// //                 cout<<"\n";
// //             }
// //         }
// //     }
// // 	return 0;
// // }

// // #include <iostream>
// // using namespace std;

// // int main() {
// // 	int t;
// // 	cin>>t;
// // 	while(t--)
// // 	{
// // 	    int n;
// // 	    cin>>n;
// // 	    if(n%2==0)
// // 	    {
// // 	    for(int i=0;i<n;i++)
// // 	    {
// // 	        for(int j=0;i<n;j++)
// // 	        {
// // 	            cout<<"-1 ";
// // 	        }
// // 	        cout<<"\n";
// // 	    }
// // 	    }
// // 	    else {
// // 	       for(int i=0;i<n;i++)
// // 	       {
// // 	        for(int j=0;i<n;j++)
// // 	        {
// // 	            if(i==j)
// // 	            cout<<"-1 ";
// // 	            else cout<<"1 ";
// // 	        }
// // 	        cout<<"\n";
// // 	        } 
// // 	    }
// // 	}
// // 	return 0;
// // }

// // #include <cmath>
// // #include <cstdio>
// // #include <vector>
// // #include <iostream>
// // #include <algorithm>
// // using namespace std;
// // int main() {
// //     int n,k,m = 0,p = 0,f = 1;
// //     cin>>n>>k;
// //     string arr[n],s[n];
// //     for(int i=0;i<n;i++)
// //     {
// //         cin>>arr[i];
// //     }
// //     if(k<2) 
// //     {
// //         cout<<"FAIL\n";
// //         return 0;
// //     }
// //     for(int i=0;i<n;i++)
// //     {
// //       for(int j=0;j<n;j++)
// //       {
// //          if(arr[i][j] == 'a')
// //          {
// //              s[m][p] = arr[i][j];
// //              p++;
// //          }
// //          else
// //          {
// //              if(arr[i][j+1] == 'a')
// //              {
// //                  cout<<"FAIL\n";
// //                  return 0;
// //              }
// //          }
// //       }
// //       m++;
// //     }
// //     sort(s,s+n);
// //     for(int i=0;i<n;i++)
// //     {
// //         cout<<s[i]<<" ";
// //     }
    
// //     return 0;
// // }
// #include "bits/stdc++.h"
// using namespace std;

// int Distance(string s1, string s2) // Calculates the distance between the two strings
// {
//     int t1 = s1.size();
//     for (long unsigned int i = 0; i < s1.size(); i++)
//     {
//         if (s1[i] == 'b')
//         {
//             t1 = i;
//             break;
//         }
//     }

//     int t2 = s2.size();
//     for (long unsigned int i = 0; i < s2.size(); i++)
//     {
//         if (s2[i] == 'b')
//         {
//             t2 = i;
//             break;
//         }
//     }
//     return abs(t1 - t2);
// }

// vector<pair<string, string>> ClosestPairRec(vector<string> s)
// {
//     if (s.size() <= 3)
//     {
//         vector<pair<string, string>> Answer;
//         int minimum = INT_MAX;
//         for (long unsigned int i = 0; i < s.size(); i++)
//         {
//             for (long unsigned int j = i + 1; j < s.size(); j++)
//             {
//                 if (Distance(s[i], s[j]) < minimum)
//                 {
//                     Answer.clear();
//                     Answer.push_back({s[i], s[j]});
//                     minimum = Distance(s[i], s[j]);
//                 }
//                 else if (Distance(s[i], s[j]) == minimum)
//                     Answer.push_back({s[i], s[j]});
//             }
//         }
//         return Answer;
//     }

//     // Dividing the given vector into two halves such that first part contains ceil(s.size()/2.0) 
//     //elements while the second half will contain floor(s.size()/2.0) elements
//     vector<string> first_half;
//     vector<string> second_half;
//     for (long unsigned int i = 0; i < s.size(); i++)
//     {
//         if (i <= (s.size() - 1) / 2)
//             first_half.push_back(s[i]);
//         else
//             second_half.push_back(s[i]);
//     }

//     vector<pair<string, string>> p1 = ClosestPairRec(first_half);
//     vector<pair<string, string>> p2 = ClosestPairRec(second_half);

//     // d = the minimum distance obtained from the two recursive calls
//     int d = min(Distance(p1[0].first, p1[0].second), Distance(p2[0].first, p2[0].second));

//     // c = the distance between the last element of first half and the first element of second half
//     int c = Distance(first_half[first_half.size() - 1], second_half[0]);

//     if (c == Distance(p1[0].first, p1[0].second))
//         p1.push_back({first_half[first_half.size() - 1], second_half[0]});
//     else if (c == Distance(p2[0].first, p2[0].second))
//         p2.insert(p2.begin(), {first_half[first_half.size() - 1], second_half[0]});

//     if (c < d)
//         return {{first_half[first_half.size() - 1], second_half[0]}};
//     if (Distance(p1[0].first, p1[0].second) < Distance(p2[0].first, p2[0].second))
//         return p1;
//     if (Distance(p2[0].first, p2[0].second) < Distance(p1[0].first, p1[0].second))
//         return p2;
//     else
//     {
//         for (long unsigned int i = 0; i < p2.size(); i++)
//         {
//             p1.push_back(p2[i]);
//         }
//         return p1;
//     }
// }

// vector<pair<string, string>> ClosestPair(vector<string> Temp)
// {
//     sort(Temp.begin(), Temp.end());
//     return ClosestPairRec(Temp);
// }

// int main(int argc, char const *argv[])
// {
//     int n;
//     long unsigned int k;
//     cin >> n >> k;
//     vector<string> s(n, "");
//     int flag = 1;
//     if (n < 2)
//         flag = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> s[i];
//         if (flag == 1)
//         {
//             if (s[i].size() != k)
//                 flag = 0;
//             else
//             {
//                 int g = 1; // To check the required format of input
//                 for (long unsigned int j = 0; j < s[i].size(); j++)
//                 {
//                     if (g == 1 && s[i][j] == 'b')
//                         g = 0;
//                     else if (g == 1 && s[i][j] != 'a')
//                     {
//                         flag = 0;
//                         break;
//                     }
//                     else if (g == 0 && s[i][j] != 'b')
//                     {
//                         flag = 0;
//                         break;
//                     }
//                 }
//             }
//         }
//     }
//     if (flag == 0 || k == 0)
//         cout << "FAIL\n";
//     else
//     {
//         vector<pair<string, string>> Result = ClosestPair(s);
//         for (long unsigned int i = 0; i < Result.size(); i++)
//         {
//             if (i != Result.size() - 1)
//                 cout << Result[i].first << "\n"<< Result[i].second << "\n\n";
//             else
//                 cout << Result[i].first << "\n"<< Result[i].second;
//         }
//     }
//     return 0;
// }

//  // for(int i=0;i<n;i++)
//     // {
//     //     temp = "";
//     //   for(int j=0;j<k;j++)
//     //   {
//     //      if(arr[i][j] == 'a')
//     //      {
//     //          temp+=arr[i][j];
//     //      }
//     //      else
//     //      {
//     //          if(j+1<k)
//     //          {
//     //             if(arr[i][j+1] == 'a')
//     //             {
//     //                  cout<<"FAIL\n";
//     //                 return 0;
//     //             }
//     //          }
//     //      }
//     //   }
//     //   s[i] = temp;
//     // }
//     // sort(s,s+n);
//     // multimap<string,string> r;
//     // r = divide(s,0,n-1,n);
//     // //r.revrese(r.begin(),r.end());
//     // for(auto p=r.rbegin();p!=r.rend();p++)
//     // {
//     //     int l1 = (p->first).length();
//     //     cout<<p->first;
//     //     for(int j=0;j<k-l1;j++)
//     //         cout<<'b';
//     //     cout<<"\n";
//     //     int l2 = (p->second).length();
//     //     cout<<p->second;
//     //     for(int j=0;j<k-l2;j++)
//     //         cout<<'b';
//     //     cout<<"\n\n";
//     // }
//    // multimap<string,string> res;
// //int c = INT_MAX;
// // bool compare(string x,string y)
// // {
// //     return (x.length()>y.length());
// // }
// // multimap<string,string> divide(string *s, int l, int r,int n)
// // {
// //     int diff = 0,m;
// //     int start = l, end = r;
// //     if(l == r-1)
// //     {
// //        diff =s[r].length() - s[l].length();
// //        //cout<<s[r].length()<<" "<<s[l].length()<<"\n";
// //        if(diff<c)
// //        {
// //            res.clear();
// //            //res.push_back(s[r]);
// //            res.insert(make_pair(s[r],s[l]));
// //            c = diff;
// //        }
// //        else if(diff == c)
// //        {
// //            // res.push_back(s[r]);
// //            // res.push_back(s[l]);
// //            //res[s[l]] = s[r];
// //            res.insert(make_pair(s[r],s[l]));
// //        }
// //     }
// //     else if( l == r)
// //     {
// //         if(l == end)
// //         {
// //         diff =s[l].length() - s[l-1].length();
// //         if(diff<c)
// //         {
// //            res.clear();
// //            // res.push_back(s[l]);
// //            // res.push_back(s[l-1]);
// //            //res[s[l]] = s[l-1];
// //         res.insert(make_pair(s[l],s[l-1]));
// //            c = diff;
// //         }
// //         else if(diff == c)
// //         {
// //            // res.push_back(s[l]);
// //            // res.push_back(s[l-1]);
// //            //res[s[l]] = s[l-1];
// //            res.insert(make_pair(s[l],s[l-1]));
// //         }
// //         }
// //         else if(l == start)
// //         {
// //         diff =s[l+1].length() - s[l].length();
// //         //cout<<s[l+1]<<" "<<s[l]<<"\n";
// //         //cout<<s[l+1].length()<<" "<<s[l].length()<<"\n";
// //         if(diff<c)
// //         {
// //            res.clear();
// //            // res.push_back(s[l]);
// //            // res.push_back(s[l+1]);
// //            //res[s[l+1]] = s[l];
// //            res.insert(make_pair(s[l+1],s[l]));
// //            c = diff;
// //         }
// //         else if(diff == c)
// //         {
// //            // res.push_back(s[l]);
// //            // res.push_back(s[l+1]);
// //            //res[s[l+1]] = s[l];
// //            res.insert(make_pair(s[l+1],s[l]));
// //         }
// //          //cout<<s[l+1]<<" "<<s[l]<<"\n";
// //         }
// //         return res;
// //     }
// //     else 
// //     {
// //         m = (l+r)/2;
// //         divide(s,m+1,r,n);
// //         divide(s,l,m-1,n); 
// //     }
// //     if(r%2==0)
// //     {
// //     int t = (n-1)/2;
// //     if(t == 1) return res;
// //     int diff1 = s[t].length()  - s[t-1].length();
// //     int diff2 = s[t+1].length() - s[t].length();
// //     if(diff1<c)
// //     {
// //         res.clear();
// //         // res.push_back(s[t]);
// //         // res.push_back(s[t-1]);
// //         //res[s[t]] = s[t-1];
// //         res.insert(make_pair(s[t],s[t-1]));
// //         c = diff1; 
// //     }
// //     else if(diff1 == c)
// //     {
// //        // res.push_back(s[t]);
// //        // res.push_back(s[t-1]); 
// //        //res[s[t]] = s[t-1];
// //        res.insert(make_pair(s[t],s[t-1]));
// //     }
// //     if(diff2<c)
// //     {
// //         res.clear();
// //         // res.push_back(s[t+1]);
// //         // res.push_back(s[t]);
// //         //res[s[t+1]] = s[t];
// //         res.insert(make_pair(s[t+1],s[t]));
// //         c = diff2; 
// //     }
// //     else if(diff2 == c)
// //     {
// //        // res.push_back(s[t+1]);
// //        // res.push_back(s[t]);
// //         //res[s[t+1]] = s[t];
// //         res.insert(make_pair(s[t+1],s[t]));
// //     }
// //     }
// //     return res;
// // }
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gcd(x,y) __gcd(x,y)
bool comp(int a,int b)
{
    return (a>b);
}
int arr[1001];
int div(int n)
{
    int c=0;
    if(arr[n]!=-1)
    return arr[n];
    else
    {
        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
            if(n/i!=i)
            c++;
            c++;
            }
        }
    }
    //cout<<"c: "<<c<<"\n";
    arr[n] = c;
    return c;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,f = 0,ind = -1,temp;
        cin>>n;
        string str,st;
        cin>>str;
        for(int i=0;i<n;i++)
        {
            cout<<"outside\n";
            if(str[i]=='0' && str[i+1]!='0' && i<n-1)
            {
                cout<<"l:\n";
                ind = i;
                f = 1;
            }
            if(f==1)
            {
                cout<<"l1:\n";
                st += str[i+1];
                i++;
                cout<<st<<"\n";
            }
        }
        // if(ind>=0)
        // st.erase(st.begin());
        // st.erase(st.begin(),st.begin()+ind);
        //else if(ind==0) st.erase(st.begin());
        cout<<"str:"<<st<<"\n";
        int tem;
        int r = 0,s = st.size();
        for(int i=0;i<=s/2;i++)
        {
            if(st[s-i-1]>st[i]) 
            {
                swap(st[s-i-1],st[i]);
                r++;
            }
            t = (st[s-i-1]-'0')%10;
            r += t;
            tem  = (st[s-i-1]-'0')-t;
            cout<<tem<<"\n";
            st[s-i-1] = tem+'0';
            //cout<<t<<" "<<r<<" "<<st[s-i-1]<<"\n";
            stringstream h(st);
            int check =-1;
            h>>check;
            if(check == 0) 
            break;
        }
        cout<<r<<"\n";
    }
    return 0;
}