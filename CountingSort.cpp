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
    //input
    int n;
    cin>>n;
    int arr[n];
    f(q, 0, n)
        cin>>arr[q];

    //processing
    map<int, int> freq;
    f(q, 0, n)
        freq[arr[q]]++;

    //output
    for(map<int, int>::iterator iter=freq.begin(); iter!=freq.end(); iter++)
        f(q, 0, iter->second)
            cout<<iter->first<<" ";
    cout<<endl;
}
