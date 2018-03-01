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
    //input
    int n;
    cin>>n;
    int arr[n];
    f(q, 0, n)
        cin>>arr[q];

    //insertion sort
    f(q, 1, n){
        int key = arr[q], index = q-1;
        while(arr[index]>key && index>-1){
            arr[index+1] = arr[index];
            index--;
        }
        arr[index+1] = key;
    }

    //output
    f(q, 0, n)
        cout<<arr[q]<<" ";
    cout<<endl;
}

