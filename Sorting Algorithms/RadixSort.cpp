/*
* Sorting is done based on digit, starting with the LSD or Least significant digit.           *
* Individual sorting is done using counting sort, repeated till all the digits are exhausted. *
* NOTE - Implementation using lesser space are possible                                       *
*/
#include <bits/stdc++.h>
using namespace std;

#define f(q, a, b) for(int q = int(a); q<int(b); q++)
#define fb(q, a, b) for(int q = int(a); q>int(b); q--)
#define pb(v, x) v.push_back(x)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

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
    //max_ keeps track of digits sorted thus far
    while(max_>0){
        max_/=10;
        //indices is for counting sort, cleared after each digit
        indices.clear();
        //arr_copy is the array from which the digits are picked
        f(q, 0, n)
            pb(indices[arr_copy[q]%10], q);
        int index = 0;
        //order the elements based on counting sort results
        for(map<int, vi>::iterator iter=indices.begin(); iter!=indices.end(); iter++)
            f(q, 0, iter->second.size())
                //arr is the array which stores the ordered elements
                //arr_copy2 is used so that elements are preserved while reordering
                arr[index++] = arr_copy2[iter->second[q]];
        f(q, 0, n){
            arr_copy2[q] = arr[q];
            //arr_copy stores the elements with digits removed, after each iteration
            arr_copy[q] = arr[q]/div;
        }
        div*=10;
    }

    //output
    f(q, 0, n)
        cout<<arr[q]<<" ";
    cout<<endl;

}
