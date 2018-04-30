/*
* Select the least element, swap it with the first element. Repeat this process n-1 times, *
* each time looking for the least element in the remaining array.                          *
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
    //taking input
    int n;
    cin>>n;
    int arr[n];
    f(q, 0, n)
        cin>>arr[q];

    //selection sort
    int iter = n-1, start = 0;
    //repeat the process for n-1 iterations
    while(iter--){
        int min_ = arr[start], swapper = start;
        //loop to find the smallest element
        f(q, start, n)
            if(arr[q]<min_){
                min_ = arr[q];
                swapper = q;
            }
        //swapping element with its correct position
        swap(arr[start], arr[swapper]);
        /*
        * each iteration finds the least element, *
        * start is increased to decrease the size *
        * of the remaining array by one           *
        */
        start++;
    }

    //output
    f(q, 0, n)
        cout<<arr[q]<<" ";
    cout<<endl;
}
