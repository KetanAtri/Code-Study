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
    //taking input
    int n;
    cin>>n;
    int arr[n];
    f(q, 0, n)
        cin>>arr[q];

    //selection sort
    int iter = n-1, start = 0;
    while(iter--){
        int min_ = arr[start], swapper = start;
        f(q, start, n)
            if(arr[q]<min_){
                min_ = arr[q];
                swapper = q;
            }
        swap(arr[start], arr[swapper]);
        start++;
    }

    //output
    f(q, 0, n)
        cout<<arr[q]<<" ";
    cout<<endl;
}
