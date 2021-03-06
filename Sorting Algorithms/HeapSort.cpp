/*
* Use the heap structure (priority queue in C++) to store the elements *
* then remove and insert them one by one to get the sorted list.       *
*/
#include <bits/stdc++.h>
using namespace std;

#define f(q, a, b) for(int q = int(a); q<int(b); q++)
#define fb(q, a, b) for(int q = int(a); q>int(b); q--)
#define pb(v, x) v.push_back(x)

typedef long long ll;
typedef unsigned long long ull;

//ifstream in("input");
//ofstream out("output");

int main()
{
    /*int t;
    cin>>t;
    while(t--){
    }*/
    //reading input and storing its negative in data type priority_queue, which is an implementation of the max heap
    //by storing the negative input we use the max heap as a min heap, since our requirement is sorting in ascending order
    int n;
    cin>>n;
    priority_queue<int> arr;
    f(q, 0, n){
        int item;
        cin>>item;
        arr.push(-item);
    }

    //output
    f(q, 0, n){
        cout<<-arr.top()<<" ";
        arr.pop();
    }

}
