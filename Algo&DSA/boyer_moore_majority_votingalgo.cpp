/*
--> When we use this algo?
  - optimal algorithms which is used to find the majority element among the given elements that have more 
    than N/ 2 occurrences. This works perfectly fine for finding the majority element which takes 2 traversals 
    the given elements, which works in O(N) time complexity and O(1) space complexity.


--> Intution behind the algorithm:
  - First, choose a candidate from the given set of elements if it is the same as the candidate element, 
    increase the votes. Otherwise, decrease the votes if votes become 0, select another new element as the 
    new candidate.

  - When the elements are the same as the candidate element, votes are incremented when some other element is 
    found not equal to the candidate element. We decreased the count. This actually means that we are decreasing
    the priority of winning ability of the selected candidate, since we know that if the candidate is a majority
    it occurs more than N/2 times and the remaining elements are less than N/2. We keep decreasing the votes since
    we found some different element than the candidate element. When votes become 0, this actually means 
    that there are the same number of different elements, which should not be the case for the element to be the 
    majority element. So the candidate element cannot be the majority, so we choose the present element as the
    candidate and continue the same till all the elements get finished. The final candidate would be our 
    majority element. We check using the 2nd traversal to see whether its count is greater than N/2. If it is
    true, we consider it as the majority element.
*/

#include <bits/stdc++.h>
using namespace std;
int majorvoting(vector<int> &v)
{
    int candidate = -1,vote = 0;
    for(int i=0;i<v.size();i++)
    {
        if(vote == 0)
        candidate = v[i];
        if(candidate==v[i])
        vote++;
        else vote--;
    }
    vote = 0;
    for(int i=0;i<v.size();i++)
    {
        if(candidate == v[i])
        vote++;
    }
    if(vote > v.size()/2)
        return candidate;
        return -1;
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
    int r = majorvoting(v);
    cout <<r<<endl;
    return 0;
}