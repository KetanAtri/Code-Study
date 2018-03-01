#include <bits/stdc++.h>
using namespace std;

#define f(q, a, b) for(int q = int(a); q<int(b); q++)
#define fb(q, a, b) for(int q = int(a); q>int(b); q--)
#define pb(v, x) v.push_back(x)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

ifstream in("input");
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
    int arr[n], arr_copy[n], arr_copy2[n], max_ = 0;
    f(q, 0, n){
        cin>>arr[q];
        if(arr[q]>max_) max_ = arr[q];
        arr_copy[q] = arr[q];
        arr_copy2[q] = arr[q];
    }

    //processing
    map<int, vi> indices;
    int div = 10;
    while(max_>0){
        max_/=10;
        indices.clear();
        f(q, 0, n)
            pb(indices[arr_copy[q]%10], q);
        int index = 0;
        for(map<int, vi>::iterator iter=indices.begin(); iter!=indices.end(); iter++)
            f(q, 0, iter->second.size())
                arr[index++] = arr_copy2[iter->second[q]];
        f(q, 0, n){
            arr_copy2[q] = arr[q];
            arr_copy[q] = arr[q]/div;
        }
        div*=10;
    }

    //output
    f(q, 0, n)
        cout<<arr[q]<<" ";
    cout<<endl;

}
