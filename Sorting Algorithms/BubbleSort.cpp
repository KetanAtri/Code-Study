/*
* Compare adjacent elements, if the former is greater than the latter, swap the two; *
* this operation is repeated n-1 times to sort the entire array                      *
*/

#include <bits/stdc++.h>
using namespace std;

#define f(q, a, b) for(int q = int(a); q<int(b); q++)
#define fb(q, a, b) for(int q = int(a); q>int(b); q--)
#define pb(v, x) v.push_back(x)

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    //taking input
    int n = 0; //n: number of elements
    cin>>n;
    int arr[n]; //arr: stores the elements
    f(q, 0, n)
        cin>>arr[q];

    int iter = n-1, n_copy = n;
    //repeat action for n-1 iterations
    while(iter--){
        //two consecutive counters
        for(int q=0, w=1; q<n-1 && w<n; q++, w++)
            //swap when necessary
            if(arr[q]>arr[w])
                swap(arr[q], arr[w]);
        /*
        * n defines the end point of the previous loop  *
        * since each iteration puts the largest element *
        * in its correct position we decrease the limit *
        * after every iteration                         *
        */
        n--;
    }

    //printing sorted array
    f(q, 0, n_copy)
        cout<<arr[q]<<" ";
    cout<<endl;
}


