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

    //bubble sort
    int iter = n-1, n_copy = n;
    while(iter--){
        for(int q=0, w=1; q<n-1 && w<n; q++, w++)
            if(arr[q]>arr[w])
                swap(arr[q], arr[w]);
        n--;
    }

    //printing sorted array
    f(q, 0, n_copy)
        cout<<arr[q]<<" ";
    cout<<endl;
}


